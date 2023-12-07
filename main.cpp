#include "Solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ColorBMPtoGrayscale <input_filename> <output_filename>" << endl << endl;
        return 1;
    }

    // Declare and read the bitmap
    BMP Input;
    Input.ReadFromFile(argv[1]);

    // Convert each pixel to grayscale using RGB->YUV
    for (int j = 0; j < Input.TellHeight(); j++) {
        for (int i = 0; i < Input.TellWidth(); i++) {
            // Convert the RGB values of the current pixel to grayscale
            int Temp = (int)floor(0.299 * Input(i, j)->Red +
                                  0.587 * Input(i, j)->Green +
                                  0.114 * Input(i, j)->Blue);

            // Convert the grayscale value to a byte
            ebmpBYTE TempBYTE = (ebmpBYTE)Temp;

            // Update the RGB values of the current pixel with the grayscale value
            Input(i, j)->Red = TempBYTE;
            Input(i, j)->Green = TempBYTE;
            Input(i, j)->Blue = TempBYTE;
        }
    }
    //This is for testing purposes and Find out the Coordinate System

    // Make one specific pixel red
    Vertex vertex;
    Vertex vertexS(0, 0);
    Vertex vertexT(639, 100);

    vertex.bestFirstSearch(Input, vertexS, vertexT);

    // Create a grayscale color table if necessary
    if (Input.TellBitDepth() < 16) {
        CreateGrayscaleColorTable(Input);
    }

////    This tells you the Input File Info:
//    cout << "File info:" << endl;
//    cout << Input.TellWidth() << " x " << Input.TellHeight()
//         << " at " << Input.TellBitDepth() << " bpp" << endl;

    // Write the output file
    Input.WriteToFile(argv[2]);


    return 0;
}
