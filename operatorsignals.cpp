#include <QDataStream>
#include <bitset>

// 重载 << 运算符以序列化 std::bitset
QDataStream& operator<<(QDataStream& out, const std::bitset<1>& bitset) {
    quint8 value = bitset.to_ulong(); // bitset<1> 可以直接转换为 unsigned long
    out << value;
    return out;
}

// 重载 >> 运算符以反序列化 std::bitset
QDataStream& operator>>(QDataStream& in, std::bitset<1>& bitset) {
    quint8 value;
    in >> value;
    bitset = std::bitset<1>(value);
    return in;
}
