#include <iostream>
#include <opencv2/opencv.hpp>

void cvt_img(std::string in_path, std::string out_path)
{
    cv::Mat img = cv::imread(in_path);
    if (img.empty())
    {
        std::cout << "图像读取失败\n";
        return;
    }
    //灰度化
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    //取反
    cv::Mat gray_inv;
    cv::bitwise_not(gray, gray_inv);
    //高斯滤波
    cv::Mat blur;
    cv::GaussianBlur(gray_inv, blur, cv::Size(15, 15), 50, 50);
    //取反
    cv::Mat blur_inv;
    cv::bitwise_not(blur, blur_inv);
    //除法
    cv::Mat res;
    cv::divide(gray, blur_inv, res, 255);
    //保存图像
    cv::imwrite(out_path, res);
}

int main()
{
    cvt_img("D:\\Pictures\\mm.png", "out.png");
}
