#include "Solution.hpp"

using namespace std;

int main() {
    string inputBMP;
    cout << "Please provide the input image:";
    cin >> inputBMP;
    cout << endl;

    int s_width = 0;
    int s_height = 0;
    int t_width = 0;
    int t_height = 0;

    cout << "Please input s_width:";
    cin >> s_width;
    cout << endl;

    cout << "Please input s_height:";
    cin >> s_height;
    cout << endl;

    cout << "Please input t_width:";
    cin >> t_width;
    cout << endl;

    cout << "Please input t_height:";
    cin >> t_height;
    cout << endl;

    // Declare and read the bitmap
    BMP Input1;
    Input1.ReadFromFile(inputBMP.c_str());

    // Convert each pixel to grayscale using RGB->YUV
    for (int j = 0; j < Input1.TellHeight(); j++) {
        for (int i = 0; i < Input1.TellWidth(); i++) {
            // Convert the RGB values of the current pixel to grayscale
            int Temp = (int)floor(0.299 * Input1(i, j)->Red +
                                  0.587 * Input1(i, j)->Green +
                                  0.114 * Input1(i, j)->Blue);

            // Convert the grayscale value to a byte
            ebmpBYTE TempBYTE = (ebmpBYTE)Temp;

            // Update the RGB values of the current pixel with the grayscale value
            Input1(i, j)->Red = TempBYTE;
            Input1(i, j)->Green = TempBYTE;
            Input1(i, j)->Blue = TempBYTE;
        }
    }
    //This is for testing purposes and Find out the Coordinate System

    // Make one specific pixel red
    Vertex vertex;
    Vertex vertexS(s_width, s_height);
    Vertex vertexT(t_width, t_height);

    vertex.breadthFirstSearch(Input1, vertexS, vertexT);

    // Create a grayscale color table if necessary
    if (Input1.TellBitDepth() < 16) {
        CreateGrayscaleColorTable(Input1);
    }
    Input1.WriteToFile("output1.bmp");

    // Declare and read the bitmap
    BMP Input2;
    Input2.ReadFromFile(inputBMP.c_str());

    // Convert each pixel to grayscale using RGB->YUV
    for (int j = 0; j < Input2.TellHeight(); j++) {
        for (int i = 0; i < Input2.TellWidth(); i++) {
            // Convert the RGB values of the current pixel to grayscale
            int Temp = (int)floor(0.299 * Input2(i, j)->Red +
                                  0.587 * Input2(i, j)->Green +
                                  0.114 * Input2(i, j)->Blue);

            // Convert the grayscale value to a byte
            ebmpBYTE TempBYTE = (ebmpBYTE)Temp;

            // Update the RGB values of the current pixel with the grayscale value
            Input2(i, j)->Red = TempBYTE;
            Input2(i, j)->Green = TempBYTE;
            Input2(i, j)->Blue = TempBYTE;
        }
    }
    //This is for testing purposes and Find out the Coordinate System

    // Make one specific pixel red
    Vertex vertex2;
    Vertex vertexS2(s_width, s_height);//S(1,10)
    Vertex vertexT2(t_width, t_height);//T(460,290)

    vertex.bestFirstSearch(Input2, vertexS2, vertexT2);

    // Create a grayscale color table if necessary
    if (Input2.TellBitDepth() < 16) {
        CreateGrayscaleColorTable(Input2);
    }
    Input2.WriteToFile("output2.bmp");


////    This tells you the Input1 File Info:
//    cout << "File info:" << endl;
//    cout << Input1.TellWidth() << " x " << Input1.TellHeight()
//         << " at " << Input1.TellBitDepth() << " bpp" << endl;

    // Write the output file


    return 0;
}
