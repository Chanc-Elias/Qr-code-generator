#include <iostream>
#include <string>
#include "qrcodegen.hpp" // Ensure this path is correct

using namespace qrcodegen;

void generateQRCode(const std::string &text) {
    QRCode qr = QRCode::encodeText(text.c_str(), QRecLevel::L);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            std::cout << (qr.getModule(x, y) ? "██" : "  ");
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string text;
    std::cout << "Enter the text to encode in QR Code: ";
    std::getline(std::cin, text);
    generateQRCode(text);
    return 0;
}
