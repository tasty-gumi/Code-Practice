#include <chrono>      // 高精度计时
#include <cstdlib>     // 生成随机数
#include <immintrin.h> // AVX intrinsics
#include <iostream>
#include <vector> // 动态数组存储大数据

// 1. AVX向量加法（每次处理8个float）
void avx_vector_add(const float *a, const float *b, float *result, size_t n) {
  // 处理能被8整除的部分（向量优化）
  for (size_t i = 0; i < n; i += 8) {
    __m256 vec_a = _mm256_loadu_ps(&a[i]); // 加载8个float
    __m256 vec_b = _mm256_loadu_ps(&b[i]);
    __m256 vec_result = _mm256_add_ps(vec_a, vec_b); // 向量加法
    _mm256_storeu_ps(&result[i], vec_result);        // 存储结果
  }
}

// 2. 普通标量加法（每次处理1个float）
void scalar_add(const float *a, const float *b, float *result, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    result[i] = a[i] + b[i]; // 逐个元素相加
  }
}

// 验证结果是否正确（确保两种方法结果一致）
bool verify_results(const float *avx_result, const float *scalar_result,
                    size_t n) {
  for (size_t i = 0; i < n; ++i) {
    if (std::abs(avx_result[i] - scalar_result[i]) >
        1e-6f) { // 允许微小浮点误差
      std::cout << "结果不一致 at index " << i << ": AVX=" << avx_result[i]
                << ", 标量=" << scalar_result[i] << std::endl;
      return false;
    }
  }
  return true;
}

int main() {
  // 生成大规模数据（10000万个float，约38MB/数组，足够大以体现差异）
  const size_t n = 100'000'000; // 必须是8的倍数（确保AVX能完整处理）

  // 分配内存（用vector避免手动管理内存，且数据在堆上，避免栈溢出）
  std::vector<float> a(n);
  std::vector<float> b(n);
  std::vector<float> avx_result(n);
  std::vector<float> scalar_result(n);

  // 填充随机数据（0.0~1000.0之间）
  std::srand(42); // 固定随机种子，确保两次加法的输入相同
  for (size_t i = 0; i < n; ++i) {
    a[i] = static_cast<float>(std::rand()) / RAND_MAX * 1000.0f;
    b[i] = static_cast<float>(std::rand()) / RAND_MAX * 1000.0f;
  }

  // ====== 测试AVX向量加法耗时 ======
  auto start = std::chrono::high_resolution_clock::now();
  avx_vector_add(a.data(), b.data(), avx_result.data(), n);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> avx_time = end - start;

  // ====== 测试普通标量加法耗时 ======
  start = std::chrono::high_resolution_clock::now();
  scalar_add(a.data(), b.data(), scalar_result.data(), n);
  end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> scalar_time = end - start;

  // 验证结果正确性（确保对比公平）
  if (!verify_results(avx_result.data(), scalar_result.data(), n)) {
    std::cerr << "结果验证失败！" << std::endl;
    return 1;
  }

  // 输出性能对比
  std::cout << "数据规模: " << n << " 个float元素" << std::endl;
  std::cout << "AVX向量加法耗时: " << avx_time.count() * 1000 << " 毫秒"
            << std::endl;
  std::cout << "普通标量加法耗时: " << scalar_time.count() * 1000 << " 毫秒"
            << std::endl;
  std::cout << "加速比: " << scalar_time.count() / avx_time.count() << " 倍"
            << std::endl;

  return 0;
}
