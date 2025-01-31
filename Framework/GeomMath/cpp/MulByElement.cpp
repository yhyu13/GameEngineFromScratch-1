#include <cstddef>
#include <cstdint>

namespace Dummy
{
    void MulByElement(const float * a, const float * b, float * result, const size_t count)
    {
        for (size_t i = 0; i < count; i++)
        {
            result[i] = a[i] * b[i];
        }
    }

    void MulByElementi16(const int16_t * a, const int16_t * b, int16_t * result, const size_t count)
    {
        for (size_t i = 0; i < count; i++)
        {
            result[i] = a[i] * b[i];
        }
    }

    void MulByElementi32(const int32_t * a, const int32_t * b, int32_t * result, const size_t count)
    {
        for (size_t i = 0; i < count; i++)
        {
            result[i] = a[i] * b[i];
        }
    }
}
