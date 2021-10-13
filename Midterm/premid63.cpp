template <typename T>
class vector {
protected:
    T *mData;
    size_t mCap, mSize; // ห้ามประกาศ data member เพิ่มเติม
public:
    // คลาสนี้ทำงานได้ตามปรกติทุกอย่าง โดยฟังก์ชันอื่น ๆ มิได้ระบุไว้เพื่อประหยัดหน้ากระดาษ ให้นิสิตเขียนบริการเพิ่มเติม ตามข้อกำหนดด้านบน
    // ให้เขียนเติมฟังก์ชันด้านล่างนี้ ให้ทำงานให้ถูกต้อง

    void unique() {
        //เขียนตรงนี้
        size_t c = 0;
        for (int i = 0; i < mSize; ++i) {
            if (i == mSize - 1 || mData[i] != mData[i + 1]) {
                mData[c++] = mData[i];
            }
        }
        mSize = c;
    }
};