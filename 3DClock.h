#pragma once

#pragma region Includes

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_OS_MAC
#include <SDL2/SDL.h>
#else
#   error "Unknown Apple platform"
#endif
#else
#   error "Unknown compiler"
#endif

#include <stdio.h>
#include <cmath>
#include <chrono>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <string>
#include <vector>
#include <omp.h>

#pragma endregion

#pragma region Structs

struct RGBValue {
    unsigned char r, g, b;
};

struct SquareFace
{
    int p1, p2, p3, p4;
    float z;
    RGBValue colour;
};

struct Edge
{
    int p1, p2;
    float z;
    RGBValue colour;
};

struct Point3D
{
    float x, y, z;
};
struct Point2D
{
    float x, y;
};

struct LineCoordinates
{
    Point2D coord1, coord2;
    float lowZCoord;
};

struct PointIndexWithZ
{
    int point;
    float z;
};

struct IndecieWithZ
{
    int p1, p2, p3;
    float z;
    unsigned char r, g, b;
};

struct EdgeWithZ
{
    int p1, p2;
    float z;
    unsigned char r, g, b;
};

struct ModelSizes
{
    int vertices, indices, edges, faces;
};

struct ProgramSettings
{
    int clearScreen;
    int randomStartColours;
    int rotatingColours;
    int renderByFaces;
    int renderByEdges;
    int projectionType;
    int rotateManually;
    int rotateXDirection;
    int rotateYDirection;
    int rotateZDirection;
};

struct Cylinder
{
    Point3D position, scaling, rotation;
};

struct Cube
{
    Point3D position, scaling, rotation;
};

#pragma endregion

#pragma region Global Variables

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

#pragma region Constants

// Preprocessor directives check the operating system and choose different SDL window flags based on it
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
const int SDL_WINDOW_SETTINGS = SDL_WINDOW_VULKAN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC;
#elif __APPLE__
#if TARGET_OS_MAC
const int SDL_WINDOW_SETTINGS = SDL_WINDOW_METAL | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC;
#else
#   error "Unknown Apple platform"
#endif
#else
#   error "Unknown compiler"
#endif

// Screen dimension
int STARTING_SCREEN_WIDTH = 500;
int STARTING_SCREEN_HEIGHT = 500;

int CURRENT_SCREEN_WIDTH = 500;
int CURRENT_SCREEN_HEIGHT = 500;

int SCALING_FACTOR = 100;

//Model Sizes
ModelSizes cubeSizes;
ModelSizes cylinderSizes;
ModelSizes pentagonalPrismSizes;
ModelSizes triangularPyramidSizes;
ModelSizes dodecagonalPrismSizes;

const float DISTANCE_FROM_EYE = 5;

bool leftMouseButtonPressed = false;
bool rightMouseButtonPressed = false;
bool lShiftPressed = false;

int xRotation = 0;
int yRotation = 0;
int zRotation = 0;

int modelChoice = 1;

double degreesToRads = M_PI / 180;
double radsToDegrees = 180 / M_PI;

enum FunctionName { Wave, MultiWave, Ripple, Sphere, Torus };
typedef Point3D(*FunctionPointer)(float, float, double);

#pragma region Model Information

#pragma region Cube Information
//Cube face colours
std::vector<unsigned char> cubeFaceColours = { 255,0,0, 255,0,0,  255,255,0, 255,255,0,  0,255,0, 0,255,0,  0,255,255, 0,255,255,  255,0,255, 255,0,255,  0,0,255, 0,0,255 };
//Cube edge colours
std::vector<unsigned char> cubeEdgeColours = { 255,0,0, 255,127,0,  255,255,0,  127,255,0,  0,255,0,  0,255,127,  0,255,255,  0,127,255,  255,0,255,  127,0,255,  0,0,255,  127,0,127 };

//The points that connect lines
std::vector<int> cubeEdges = {
    0,1, 1,2, 2,3, 3,0, // Front
    4,5, 5,6, 6,7, 7,4, // Back
    0,4,
    1,5,
    2,6,
    3,7
};

std::vector<int> cubeIndices = {
    0,1,2, 0,2,3, // Front
    1,5,6, 1,6,2, // Right
    5,4,7, 5,7,6, // Back
    4,0,3, 4,3,7, // Left
    4,5,1, 4,1,0, // Top
    7,6,2, 7,2,3, // Bottom
};
#pragma endregion


#pragma endregion

#pragma endregion

#pragma endregion

#pragma region Function Prototyping
//Starts up SDL and creates window
bool init();

Point3D WaveFunc(float u, float v, double rotation);

Point3D MultiWaveFunc(float u, float v, double rotation);

Point3D SphereFunc(float u, float v, double rotation);

Point3D RippleFunc(float u, float v, double rotation);

Point3D TorusFunc(float u, float v, double rotation);

void renderMathFunction(std::vector<Point3D>& points, int pointsResolution, float step, double rotation, ProgramSettings programSettings, FunctionName function);

//Frees media and shuts down SDL
void close();

void randomizeFaceColours(std::vector<unsigned char>& faceColours);

void randomizeEdgeColours(std::vector<unsigned char>& edgeColours);

// Checks the scaling factor compared to the screen size
void checkScalingFactor();

void createCubeModel(Cube model, std::vector<unsigned char> faceColours, std::vector<Point3D>& finalModel);

void createCylinderModel(Cylinder model, std::vector<unsigned char> faceColours, std::vector<Point3D>& finalModel);

//This method takes and returns a Point3D, it converts the 3D coordinates to 2D coordinates using a perspective algorithm
Point3D PerspectiveProjection(Point3D& point);

Point3D OrthographicProjection(Point3D& point);

//This function takes a Point3D, a rotation value and returns a rotated Point3D, it rotates on the x axis
Point3D rotateXAxis(Point3D& original, double rotation);

//This function takes a Point3D, a rotation value and returns a rotated Point3D, it rotates on the y axis
Point3D rotateYAxis(Point3D& original, double rotation);

//This function takes a Point3D, a rotation value and returns a rotated Point3D, it rotates on the z axis
Point3D rotateZAxis(Point3D& original, double rotation);

Point3D rotateAllDirection(Point3D point, double rotation);

//Copies a matrix from one var to another
void copyMatrix(Point3D& original, Point3D& copy);

void calculateObjectProjection(std::vector<Point3D>& projectedPointWithZ, double rotation, std::vector<Point3D> model, ModelSizes modelSize, Point3D positionShift, ProgramSettings programSettings);

void renderModelByEdges(std::vector<Point3D> projectedPointWithZ, std::vector<int> cubeEdgeArr, std::vector<EdgeWithZ> arrayOfEdgesWithZ, ModelSizes cubeSizes, std::vector<unsigned char> cubeEdgeColours);

void renderModel(double rotation, std::vector<Point3D> model, std::vector<int> indicies, std::vector<int> edges, ModelSizes modelSize, std::vector<unsigned char> faceColours, std::vector<unsigned char> edgeColours, ProgramSettings programSettings, Point3D positionShift);

void sortFaces(std::vector<int> indicies, std::vector<Point3D> projectedPointWithZ, std::vector<IndecieWithZ>& arrayOfFaceIndicesWithZ, ModelSizes cubeSizes, std::vector<unsigned char> cubeFaceColours);

void renderModelByIndicies(std::vector<Point3D> projectedPointWithZ, std::vector<int> cubeIndicesArr, std::vector<IndecieWithZ> arrayOfFaceIndicesWithZ, ModelSizes cubeSizes, std::vector<unsigned char> cubeFaceColours);

#pragma endregion

FunctionPointer functionPointers[] = { WaveFunc, MultiWaveFunc, RippleFunc, SphereFunc, TorusFunc };



