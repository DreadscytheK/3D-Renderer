#include "3DClock.h"


int main(int argc, char* args[])
{

#pragma region Variables

#pragma region Arrays

#pragma region Dodecagonal Prism

	//This vector holds the x,y,z values for each coordinate, this is a 3d object
	std::vector<Point3D> dodecagonalPrismModel = {
		/*Front Face*/{-0.33,-1,-0.1}, {0.33,-1,-0.1}, {0.75,-0.75,-0.1}, {1, -0.33,-0.1}, {1, 0.33,-0.1}, {0.75, 0.75,-0.1}, {0.33, 1,-0.1}, {-0.33, 1,-0.1}, {-0.75, 0.75,-0.1}, {-1, 0.33,-0.1}, {-1, -0.33,-0.1}, {-0.75, -0.75,-0.1},
		/*Back  Face*/{-0.33,-1,0.1}, {0.33,-1,0.1}, {0.75,-0.75,0.1}, {1, -0.33,0.1}, {1, 0.33,0.1}, {0.75, 0.75,0.1}, {0.33, 1,0.1}, {-0.33, 1,0.1}, {-0.75, 0.75,0.1}, {-1, 0.33,0.1}, {-1, -0.33,0.1}, {-0.75, -0.75,0.1} };

	std::vector<unsigned char> dodecagonalPrismFaceColour = { 168, 168, 168 };

	//1st, 2nd, 3rd, and 6th numbers per row are all unique
	std::vector<int> dodecagonalPrismEdges = {
		0,1, 1,2, 2,3, 3,4, 4,5, 5,6, 6,7, 7,8, 8,9, 9,10, 10,11, 11,0, // Front

		12,13, 13,14, 14,15, 15,16, 16,17, 17,18, 18,19, 19,20, 20,21, 21,22, 22,23, 23,12, // Back

		0,12,   // Edge 1
		1,13,   // Edge 2
		2,14,   // Edge 3
		3,15,   // Edge 4
		4,16,   // Edge 5
		5,17,   // Edge 6
		6,18,   // Edge 7
		7,19,   // Edge 8
		8,20,   // Edge 9
		9,21,   // Edge 10
		10,22,  // Edge 11
		11,23   // Edge 12
	};

	//1st, 2nd, 3rd, and 6th numbers per row are all unique
	std::vector<int> dodecagonalPrismIndices = {
		9,10,11, 9,8,11, // Front
		8,11,0, 8,7,0,
		7,0,1, 7,6,1,
		6,1,2, 6,5,2,
		5,2,3, 5,4,3,

		21,22,23, 21,20,23, // Back
		20,23,12, 20,19,12,
		19,12,13, 19,18,13,
		18,13,14, 18,17,14,
		17,14,15, 17,16,15,

		12,13,0, 13,1,0,    // Side 1 (top)
		13,14,1, 14,2,1,    // Side 2
		14,15,2, 15,3,2,    // Side 3
		15,16,3, 16,4,3,    // Side 4
		16,17,4, 17,5,4,    // Side 5
		17,18,5, 18,6,5,    // Side 6
		18,19,6, 19,7,6,    // Side 7
		19,20,7, 20,8,7,    // Side 8
		20,21,8, 21,9,8,    // Side 9
		21,22,9, 22,10,9,   // Side 10
		22,23,10, 23,11,10, // Side 11
		23,12,11, 12,0,11,  // Side 11
	};

#pragma endregion

#pragma region Original Cube

	//This vector holds the x,y,z values for each coordinate, this is a 3d object
	std::vector<Point3D> originalCubeModel = { { -1,-1,-1 }, { 1,-1,-1 }, { 1,1,-1 }, { -1, 1,-1 },
											   { -1,-1, 1 }, { 1,-1, 1 }, { 1,1, 1 }, { -1, 1, 1 } };
#pragma endregion

#pragma region New Cube
	Prism newCubeDimensions = {
		{ 4 },	      // Number of sides
		{ 0, 0, 0 },  // Position
		{ 1, 1, 1 },  // Scaling
		{ 0, 0, 0 }   // Rotation
	};

	std::vector<Point3D> cubeNewModel;
	std::vector<int> cubeNewEdges;
	std::vector<int> cubeNewIndices;

	ModelSizes cubeNewSizes;

	std::vector<unsigned char> cubeNewColour = { 255, 000, 000, 255, 000, 000, 255, 000, 000, 255, 000, 000, 255, 000, 000, 255, 000, 000,
											     255, 255, 000, 255, 255, 000, 255, 255, 000, 255, 255, 000, 255, 255, 000, 255, 255, 000,
											     000, 255, 000, 000, 255, 000, 000, 255, 000, 000, 255, 000, 000, 255, 000, 000, 255, 000,
											     000, 255, 255, 000, 255, 255, 000, 255, 255, 000, 255, 255, 000, 255, 255, 000, 255, 255,
											     255, 000, 255, 255, 000, 255, 255, 000, 255, 255, 000, 255, 255, 000, 255, 255, 000, 255,
											     000, 000, 255, 000, 000, 255, 000, 000, 255, 000, 000, 255, 000, 000, 255, 000, 000, 255, };

#pragma endregion

#pragma region hour12
	Prism hour12 = {
		{ 4 },				 // Number of sides
		{ 0, 0, 0, },      // Position
		{ 0.1, 0.2, 0.05 },  // Scaling
		{ 0, 0, 0}           // Rotation
	};

	std::vector<Point3D> hour12Model;
	std::vector<int> hour12Edges;
	std::vector<int> hour12Indices;

	ModelSizes hour12Sizes;


	std::vector<unsigned char> hour12Colour = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
											    100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
											    100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
											    100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
											    100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
											    100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, };

	std::vector<unsigned char> clockHourFaceColours = { 255,0,0, 255,0,0,  255,255,0, 255,255,0,  0,255,0, 0,255,0,  0,255,255, 0,255,255,  255,0,255, 255,0,255,  0,0,255, 0,0,255 };
#pragma endregion

#pragma region Clock Face
	Prism clockFaceDimensions = {
		{ 16 },		      // Number of sides
		{ 0, 0, 0, },     // Position
		{ 0.2, 2, 0.2 },  // Scaling
		{ 0, 0, 0}        // Rotation
	};

	std::vector<Point3D> clockFaceModel;
	std::vector<unsigned char> clockColour;

	std::vector<int> clockEdges;
	std::vector<int> clockIndices;

	ModelSizes clockSizes;

	std::vector<unsigned char> cylinderFaceColours = { 255,0,0 };
	std::vector<unsigned char> cylinderEdgeColours = { 255,0,0 };
#pragma endregion

#pragma region Points Array
	int pointsResolution = 200;
	std::vector<Point3D> points;
#pragma endregion

#pragma endregion
	//Program settings
	ProgramSettings programSettings;
	programSettings.clearScreen = 1;
	programSettings.randomStartColours = 0;
	programSettings.rotatingColours = 0;
	programSettings.renderByEdges = 0;
	programSettings.renderByFaces = 1;
	programSettings.projectionType = 0;
	programSettings.rotateManually = 1;
	programSettings.rotateXDirection = 0;
	programSettings.rotateYDirection = 0;
	programSettings.rotateZDirection = 0;

	//Rotation, this is the number of degress the model rotates by, uses a timer to count the time between renders and adds that time to itself
	double rotation = 0.0;

	bool quit = false;

	//Start and end times for checking time
	std::chrono::steady_clock::time_point startTime, endTime;

	//The difference in time
	std::chrono::duration<double> duration(0);

	cubeSizes.edges = 12;
	cubeSizes.faces = 6;
	cubeSizes.indices = 36;
	cubeSizes.vertices = 8;

	cylinderSizes.edges = 48;
	cylinderSizes.faces = 18;
	cylinderSizes.indices = 180;
	cylinderSizes.vertices = 32;
	float step = 2.0f / pointsResolution;

	
#pragma endregion

#pragma region Code

	//Randomizes the colours
	if (programSettings.randomStartColours == 1) {
		randomizeFaceColours(cubeFaceColours);
	}

	//Initializing Points array
	for (int i = 0; i < pointsResolution * pointsResolution; i++) {
		points.push_back(Point3D{ 0,0,0 });
	}


	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
		return 1;
	}

	//loadMedia();

	// Seed the random number generator with the current time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));


	//Creating cube and cylinder test models
	//createPrismModel(hour12, hour12Model, hour12Edges, hour12Indices, hour12Sizes, blank);
	createPrismModel(newCubeDimensions, cubeNewModel, cubeNewEdges, cubeNewIndices, cubeNewSizes, blank);
	createPrismModel(clockFaceDimensions, clockFaceModel, clockEdges, clockIndices, clockSizes, clockColour);

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit)
	{
#pragma region SDL Events
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEWHEEL:
				if (e.wheel.y > 0) // scroll up
				{
					SCALING_FACTOR += 25;
				}
				else if (e.wheel.y < 0) // scroll down
				{
					SCALING_FACTOR -= 25;

					if (SCALING_FACTOR <= 0) {
						SCALING_FACTOR = 10;
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (e.button.button == SDL_BUTTON_LEFT) {
					leftMouseButtonPressed = true;
				}
				else if(e.button.button == SDL_BUTTON_RIGHT){
					rightMouseButtonPressed = true;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT) {
					leftMouseButtonPressed = false;
				}
				else if (e.button.button == SDL_BUTTON_RIGHT) {
					rightMouseButtonPressed = false;
				}
				break;
			case SDL_MOUSEMOTION:
				if (leftMouseButtonPressed == true) {
					if (e.motion.yrel > 0) // scroll up
					{
						xRotation += 2;
					}
					else if (e.motion.yrel < 0) // scroll down
					{
						xRotation -= 2;
					}

					if (e.motion.xrel > 0) // scroll up
					{
						yRotation -= 2;
					}
					else if (e.motion.xrel < 0) // scroll down
					{
						yRotation += 2;
					}
				}
				if (rightMouseButtonPressed == true) {
					if (e.motion.yrel > 0) // scroll up
					{
						SCALING_FACTOR += 25;
					}
					else if (e.motion.yrel < 0) // scroll down
					{
						SCALING_FACTOR -= 25;
						if (SCALING_FACTOR <= 0) {
							SCALING_FACTOR = 10;
						}
					}
				}
			case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_LSHIFT) {
					lShiftPressed == true;
				}

				switch (e.key.keysym.sym) {
					//Cycle through models and math functions
				case SDLK_1:
					modelChoice = SDLK_1 % 48;
					break;
				case SDLK_2:
					modelChoice = SDLK_2 % 48;
					break;
				case SDLK_3:
					modelChoice = SDLK_3 % 48;
					break;
				case SDLK_4:
					modelChoice = SDLK_4 % 48;
					break;
				case SDLK_5:
					modelChoice = SDLK_5 % 48;
					break;
				case SDLK_6:
					modelChoice = SDLK_6 % 48;
					break;
				case SDLK_7:
					modelChoice = SDLK_7 % 48;
					break;
				case SDLK_8:
					modelChoice = SDLK_8 % 48;
					break;
				case SDLK_9:
					modelChoice = SDLK_9 % 48;
					break;

					//Render By Edges
				case SDLK_e:
					programSettings.renderByEdges = 1;
					programSettings.renderByFaces = 0;
					break;
					//Render By Faces
				case SDLK_f:
					programSettings.renderByEdges = 0;
					programSettings.renderByFaces = 1;
					break;

					//Use orthographic projection
				case SDLK_o:
					programSettings.projectionType = 1;
					break;
					//Use perspective projection
				case SDLK_p:
					programSettings.projectionType = 0;
					break;

					//Rotate manually
				case SDLK_r:
					programSettings.rotateManually = 1;
					programSettings.rotateXDirection = 0;
					programSettings.rotateYDirection = 0;
					programSettings.rotateZDirection = 0;
					break;
					//Rotate on all axis automatically
				case SDLK_a:
					programSettings.rotateManually = 0;
					programSettings.rotateXDirection = 1;
					programSettings.rotateYDirection = 1;
					programSettings.rotateZDirection = 1;
					rotation = 0;
					break;
					//Reset to front view
				case SDLK_d:
					xRotation = 0;
					yRotation = 0;
					zRotation = 0;
					rotation = 0;
					break;
					//Rotate on x axis automatically
				case SDLK_x:
					programSettings.rotateManually = 0;
					programSettings.rotateXDirection = 1;
					programSettings.rotateYDirection = 0;
					programSettings.rotateZDirection = 0;
					rotation = 0;
					break;
					//Rotate on y axis automatically
				case SDLK_y:
					programSettings.rotateManually = 0;
					programSettings.rotateXDirection = 0;
					programSettings.rotateYDirection = 1;
					programSettings.rotateZDirection = 0;
					rotation = 0;
					break;
					//Rotate on z axis automatically
				case SDLK_z:
					programSettings.rotateManually = 0;
					programSettings.rotateXDirection = 0;
					programSettings.rotateYDirection = 0;
					programSettings.rotateZDirection = 1;
					rotation = 0;
					break;

				case SDLK_UP:
					if (lShiftPressed == true) {
						xRotation -= 90;
					}
					else {
						xRotation -= 3;
					}
					break;
				case SDLK_DOWN:
					if (lShiftPressed == true) {
						xRotation += 90;
					}
					else {
						xRotation += 3;
					}
					break;
				case SDLK_LEFT:
					if (lShiftPressed == true) {
						yRotation += 90;
					}
					else {
						yRotation += 3;
					}
					break;
				case SDLK_RIGHT:
					if (lShiftPressed == true) {
						yRotation -= 90;
					}
					else {
						yRotation -= 3;
					}
					break;
				}

				case SDL_KEYUP:
					if (e.key.keysym.sym == SDLK_LSHIFT) {
						lShiftPressed == false;
					}
					break;
			
				
				break;

				Default:
					break;
			}
		}
#pragma endregion

		Uint32 start_time, frame_time;
		float fps;

		start_time = SDL_GetTicks();
		//Every loop it checks if the screen width or height has changed in order to change the scaling factor
		checkScalingFactor();

		//Gets the time now
		startTime = std::chrono::high_resolution_clock::now();

		//Determines whether to clear the screen or not
		if (programSettings.clearScreen == 1) {
			//Clears the screen and resets the draw colour to black
			SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(gRenderer);
		}


		//Render texture to screen
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

		switch (modelChoice) {
		case 1:
			////Renders the classic cube
			//renderModel(rotation, originalCubeModel, cubeIndices, cubeEdges, cubeSizes, hour12Colour, hour12Colour, programSettings, Point3D{ 0,0,0 });
			break;
		case 2:
			//Renders the new pos,scal,rot based cube
			renderModel(rotation, cubeNewModel, cubeIndices, cubeEdges, cubeNewSizes, cubeNewColour, cubeNewColour, programSettings, Point3D{ 0,0,0 });
			break;
		case 3:
			renderModel(rotation, hour12Model, hour12Indices, hour12Edges, hour12Sizes, hour12Colour, hour12Colour, programSettings, Point3D{ 0,0,0 });
			//renderModel(rotation, clockFaceModel, clockIndices, clockEdges, clockSizes, clockColour, clockColour, programSettings, Point3D{ 0,0,0 });
			break;
		case 4:
			//renderModel(rotation, hour12Model, cubeIndices, cubeEdges, cubeSizes, clockHourColours, cubeEdgeColours, programSettings, Point3D{ 0,0,0 });
			renderModel(rotation, clockFaceModel, clockIndices, clockEdges, clockSizes, clockColour, clockColour, programSettings, Point3D{ 0,0,0 });
			break;
		case 5:
			renderMathFunction(points, pointsResolution, step, rotation, programSettings, Wave);
			break;
		case 6:
			renderMathFunction(points, pointsResolution, step, rotation, programSettings, MultiWave);
			break;
		case 7:
			renderMathFunction(points, pointsResolution, step, rotation, programSettings, Ripple);
			break;
		case 8:
			renderMathFunction(points, pointsResolution, step, rotation, programSettings, Sphere);
			break;
		case 9:
			renderMathFunction(points, pointsResolution, step, rotation, programSettings, Torus);
			break;
		default:
			break;
		}

		// Renders the model
		SDL_RenderPresent(gRenderer);

		// Gets the current time
		endTime = std::chrono::high_resolution_clock::now();

		//Calculates the difference between the start time and the end time
		duration = endTime - startTime;

		//Increment roation by the difference between start and end times
		rotation += duration.count();

		if (programSettings.rotateManually == 0) {
			if (programSettings.rotateXDirection == 1) {
				xRotation = rotation * radsToDegrees;
			}
			if (programSettings.rotateYDirection == 1) {
				yRotation = rotation * radsToDegrees;
			}
			if (programSettings.rotateZDirection == 1) {
				zRotation = rotation * radsToDegrees;
			}
		}

		startTime = endTime;
		frame_time = SDL_GetTicks() - start_time;
		fps = (frame_time > 0) ? 1000.0f / frame_time : 1000.0f;
		printf("%f\n", fps);

	}


	//Free resources and close SDL
	close();

	return 0;

#pragma endregion

}

void renderMathFunction(std::vector<Point3D>& points, int pointsResolution, float step, double rotation, ProgramSettings programSettings, FunctionName function)
{
	float v = 0.5f * step - 1.0f;

	for (int i = 0, x = 0, z = 0; i < points.size(); i++, x++)
	{
		if (x == pointsResolution)
		{
			x = 0;
			z += 1;
			v = (z + 0.5f) * step - 1.0f;
		}
		float u = (x + 0.5f) * step - 1.0f;
		points[i] = functionPointers[function](u, v, rotation);

		Point3D temp;

		temp = points[i];

		int xColour = 255;
		int yColour = 255;
		int zColour = 255;

		/*xColour = (abs(temp.x) / 1) * 255;
		yColour = (abs(temp.y) / 1) * 255;
		zColour = (abs(temp.z) / 1) * 255;*/

		xColour = (temp.x / 1) * 255;
		yColour = (temp.y / 1) * 255;
		zColour = (temp.z / 1) * 255;

		temp = rotateXAxis(temp, xRotation * degreesToRads);
		temp = rotateYAxis(temp, yRotation * degreesToRads);
		temp = rotateZAxis(temp, zRotation * degreesToRads);

		if (programSettings.projectionType == 0) {
			temp = PerspectiveProjection(temp);
		}
		else {
			temp = OrthographicProjection(temp);
		}
		

		SDL_SetRenderDrawColor(gRenderer, xColour, yColour, zColour, SDL_ALPHA_OPAQUE);

		SDL_RenderDrawPointF(gRenderer, temp.x, temp.y);
	}
}

Point3D WaveFunc(float u, float v, double rotation)
{
	Point3D tempX;
	tempX.x = u;
	tempX.y = sin(M_PI * (u + v + rotation));
	tempX.z = v;

	return tempX;
}

Point3D MultiWaveFunc(float u, float v, double rotation) {
	Point3D p;
	p.x = u;
	p.y = sin(M_PI * (u + 0.5f * rotation));
	p.y += 0.5f * sin(2.0f * M_PI * (v + rotation));
	p.y += sin(M_PI * (u + v + 0.25f * rotation));
	p.y *= 1.0f / 2.5f;
	p.z = v;
	return p;
}

Point3D SphereFunc(float u, float v, double rotation)
{
	float r = 0.9f + 0.1f * sin(M_PI * (6.0f * u + 4.0f * v + rotation));
	float s = r * cos(0.5f * M_PI * v);
	Point3D p;
	p.x = s * sin(M_PI * u);
	p.y = r * sin(M_PI * 0.5f * v);
	p.z = s * cos(M_PI * u);
	return p;
}

Point3D RippleFunc(float u, float v, double rotation)
{
	float d = sqrt(u * u + v * v);
	Point3D p;
	p.x = u;
	p.y = sin(M_PI * (4.0f * d - rotation));
	p.y /= 1.0f + 10.0f * d;
	p.z = v;
	return p;
}

Point3D TorusFunc(float u, float v, double rotation)
{
	float r1 = 0.7f + 0.1f * sin(M_PI * (6.0f * u + 0.5f * rotation));
	float r2 = 0.15f + 0.05f * sin(M_PI * (8.0f * u + 4.0f * v + 2.0f * rotation));
	float s = r1 + r2 * cos(M_PI * v);
	Point3D p;
	p.x = s * sin(M_PI * u);
	p.y = r2 * sin(M_PI * v);
	p.z = s * cos(M_PI * u);
	return p;
}

//Starts up SDL and creates window
bool init()
{
	SDL_DisplayMode DM;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	if (SDL_GetCurrentDisplayMode(0, &DM) != 0) {
		printf("SDL_GetDesktopDisplayMode failed: %s\n", SDL_GetError());

		return false;
	}

	STARTING_SCREEN_WIDTH = DM.w;
	STARTING_SCREEN_HEIGHT = DM.h;

	//Create window
	gWindow = SDL_CreateWindow("Rotating Square", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, STARTING_SCREEN_WIDTH, STARTING_SCREEN_HEIGHT, SDL_WINDOW_SETTINGS);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	int windowWidth, windowHeight;
	SDL_GetWindowSize(gWindow, &windowWidth, &windowHeight);

	//Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	//Initialize renderer color
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}
	else
	{
		//Get window surface
		gScreenSurface = SDL_GetWindowSurface(gWindow);
	}

	return true;
}

SDL_Surface* loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	gTexture = loadTexture("sponge (Custom).png");
	if (gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	return success;
}

//Frees media and shuts down SDL
void close()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void checkScalingFactor() {
	int tempScreenWidth, tempScreenHeight;
	SDL_GetWindowSize(gWindow, &tempScreenWidth, &tempScreenHeight);
	if (tempScreenWidth != CURRENT_SCREEN_WIDTH || tempScreenHeight != CURRENT_SCREEN_HEIGHT) {
		CURRENT_SCREEN_WIDTH = tempScreenWidth;
		CURRENT_SCREEN_HEIGHT = tempScreenHeight;

		float screenWidthRatio = (float)CURRENT_SCREEN_WIDTH / STARTING_SCREEN_WIDTH;
		float screenHeightRatio = (float)CURRENT_SCREEN_HEIGHT / STARTING_SCREEN_HEIGHT;

		if (screenWidthRatio < screenHeightRatio) {
			SCALING_FACTOR = SCALING_FACTOR + screenWidthRatio * 300;
		}
		else {
			SCALING_FACTOR = SCALING_FACTOR + screenHeightRatio * 300;
		}
	}
}

//This method takes and returns a Point3D, it converts the 3d coordinates to 2d coordinates using a perspective algorithm
Point3D PerspectiveProjection(Point3D& point) {
	return Point3D{
		CURRENT_SCREEN_WIDTH / 2 + (point.x * DISTANCE_FROM_EYE) / (DISTANCE_FROM_EYE + point.z) * SCALING_FACTOR,
		CURRENT_SCREEN_HEIGHT / 2 + (point.y * DISTANCE_FROM_EYE) / (DISTANCE_FROM_EYE + point.z) * SCALING_FACTOR,
		point.z * -1
	};
}

Point3D OrthographicProjection(Point3D& point) {
	return Point3D{
		CURRENT_SCREEN_WIDTH / 2 + (point.x) * SCALING_FACTOR,
		CURRENT_SCREEN_HEIGHT / 2 + (point.y) * SCALING_FACTOR,
		point.z * -1
	};
}

void createPrismModel(Prism model, std::vector<Point3D>& finalModel, std::vector<int>& prismEdges, std::vector<int>& prismIndices, ModelSizes& prismSizes, std::vector<unsigned char>& prismColour) {
	int numberOfSides = model.numberOfSides;
	int indiceIndex = 0;
	int currentIndice = 2;
	int currentIndicePlusSides = currentIndice + numberOfSides;
	float degreeShift = 360.0f / numberOfSides;
	bool noColour = false;
	//Size of the cylinderIndices array
	int cylinderIndicesSize = ((numberOfSides - 2) * 6) + (numberOfSides * 6);

	//Determines a single point the size of the object, likely on the left
	float point1X = -(model.scaling.x / 2) + (model.position.x) / 100;
	float point1Y = -(model.scaling.y / 2) + -(model.position.y) / 100;
	float calcZPos = (model.scaling.z / 2) + -(model.position.z) / 100;
	float calcZNeg = -(model.scaling.z / 2) + -(model.position.z) / 100;

	Point3D frontPoint = { point1X, point1Y, calcZNeg };
	Point3D backPoint = { point1X, point1Y, calcZPos };

	/* Setting up front and back points */

	//Determines the location of vertices for front
	for (int rotationIndex = 0; rotationIndex < numberOfSides; rotationIndex++) {
		Point3D temp = frontPoint;
		float rotation = (degreeShift * rotationIndex) * degreesToRads;

		temp.x = cos(rotation) * model.scaling.x * frontPoint.x - sin(rotation) * frontPoint.y;
		temp.y = sin(rotation) * frontPoint.x + cos(rotation) * model.scaling.y * frontPoint.y;

		finalModel.push_back(temp);
		//finalModel.push_back(rotateZAxis(frontPoint, (degreeShift * rotationIndex) * degreesToRads));
	}

	//Determines the location of vertices for back
	for (int rotationIndex = 0; rotationIndex < numberOfSides; rotationIndex++) {
		Point3D temp = backPoint;
		float rotation = (degreeShift * rotationIndex) * degreesToRads;

		temp.x = cos(rotation) * model.scaling.x * frontPoint.x - sin(rotation) * frontPoint.y;
		temp.y = sin(rotation) * frontPoint.x + cos(rotation) * model.scaling.y * frontPoint.y;

		finalModel.push_back(temp);

		//finalModel.push_back(rotateZAxis(backPoint, (degreeShift * rotationIndex) * degreesToRads));
	}
	
	/* Determining edge locations */

	//Connects the vertices of the front face
	for (int edgeIndex = 0; edgeIndex < numberOfSides; edgeIndex++) {
		prismEdges.push_back(edgeIndex);
		prismEdges.push_back(edgeIndex + 1);
	}

	//Sets the last element of the previously allocated elements to 0
	prismEdges[(numberOfSides * 2) - 1] = 0;

	//Connects the vertices of the back face
	for (int edgeIndex = numberOfSides; edgeIndex < numberOfSides * 2; edgeIndex++) {
		prismEdges.push_back(edgeIndex);
		prismEdges.push_back(edgeIndex + 1);
	}

	//Sets the last element of the previously allocated elements to the number of sides
	prismEdges[(numberOfSides * 4) - 1] = numberOfSides;

	//Connects the vertices between the front and back faces
	for (int edgeIndex = 0; edgeIndex < numberOfSides; edgeIndex++) {
		prismEdges.push_back(edgeIndex);
		prismEdges.push_back(edgeIndex + numberOfSides);
	}

	/* Determining indice locations */

	if (prismColour.size() == 1) {
		noColour = true;
	}

	//Resizing the indices array so they can be filled
	prismIndices.resize(cylinderIndicesSize, 0);
	
	//Filling the array with zeroes
	std::fill(prismIndices.begin(), prismIndices.end(), 0);

	if (noColour == false) {
		//Resizing the colour array so they can be filled
		prismColour.resize(cylinderIndicesSize * 3);
		//Filling the array with zeroes
		std::fill(prismColour.begin(), prismColour.end(), 0);

		//Colours for the front face
		for (int colourIndex = 0; colourIndex < ((numberOfSides - 2) * 9); colourIndex += 3) {
			prismColour[colourIndex] = 255;
		}

		//Colours for the back face
		for (int colourIndex = ((numberOfSides - 2) * 9) + 2; colourIndex < ((numberOfSides - 2) * 18); colourIndex += 3) {
			prismColour[colourIndex] = 255;
		}

		float colourIncValue = (255 - 100) / numberOfSides * 2;
		int colourIncIndex = 0;

		for (int colourIndex = ((numberOfSides - 2) * 18) + 1; colourIndex < ((numberOfSides - 2) * 18) + (numberOfSides * 18); colourIndex += 18) {
			prismColour[colourIndex] = 100 + (colourIncValue * colourIncIndex);
			prismColour[colourIndex + 3] = 100 + (colourIncValue * colourIncIndex);
			prismColour[colourIndex + 6] = 100 + (colourIncValue * colourIncIndex);

			prismColour[colourIndex + 9] = 100 + (colourIncValue * colourIncIndex);
			prismColour[colourIndex + 12] = 100 + (colourIncValue * colourIncIndex);
			prismColour[colourIndex + 15] = 100 + (colourIncValue * colourIncIndex++);
		}
	}

	//These are always the same no matter how many sides
	prismIndices[0] = 0;
	prismIndices[1] = 1;
	prismIndices[2] = numberOfSides - 1;

	prismIndices[3] = 1;
	prismIndices[4] = 2;
	prismIndices[5] = numberOfSides - 1;
	
	//Calculating front face indices
	//indiceIndex set to 6 to skip the previously done first 2 indices, 
	//goes until all triangles are found, so numberOfSides - 2,
	//multiplied by 3 because of how it is stored
	for (indiceIndex = 6; indiceIndex < ((numberOfSides - 2) * 3); indiceIndex+=3) {
		prismIndices[indiceIndex] = currentIndice;
		prismIndices[indiceIndex + 2] = numberOfSides - currentIndice;
		
		if (indiceIndex % 2 == 1) {
			prismIndices[indiceIndex + 1] = currentIndice + 1;
			currentIndice++;
		}
		else {
			prismIndices[indiceIndex + 1] = (numberOfSides + 1) - currentIndice;
		}
	}

	//These are always the same no matter how many sides
	prismIndices[indiceIndex++] = numberOfSides;
	prismIndices[indiceIndex++] = numberOfSides + 1;
	prismIndices[indiceIndex++] = (numberOfSides * 2) - 1;
								   
	prismIndices[indiceIndex++] = numberOfSides + 1;
	prismIndices[indiceIndex++] = numberOfSides + 2;
	prismIndices[indiceIndex++] = (numberOfSides * 2) - 1;

	currentIndice = 2;

	for (indiceIndex; indiceIndex < ((numberOfSides - 2) * 6); indiceIndex+=3) {
		prismIndices[indiceIndex] = currentIndicePlusSides;
		prismIndices[indiceIndex + 2] = numberOfSides * 2 - currentIndice;

		if (numberOfSides % 2 == 0) {
			if (indiceIndex % 2 == 1) {
				prismIndices[indiceIndex + 1] = currentIndicePlusSides + 1;
				currentIndicePlusSides++;
				currentIndice++;
			}
			else {
				prismIndices[indiceIndex + 1] = ((numberOfSides * 2) + 1) - currentIndice;
			}
		}
		else {
			if (indiceIndex % 2 == 0) {
				prismIndices[indiceIndex + 1] = currentIndicePlusSides + 1;
				currentIndicePlusSides++;
				currentIndice++;
			}
			else {
				prismIndices[indiceIndex + 1] = ((numberOfSides * 2) + 1) - currentIndice;
			}
		}
	}

	currentIndice = 0;

	for (indiceIndex; indiceIndex < ((numberOfSides - 2) * 6) + ((numberOfSides - 1) * 6); indiceIndex += 6) {
		prismIndices[indiceIndex] = currentIndice + numberOfSides;
		prismIndices[indiceIndex + 1] = currentIndice + numberOfSides + 1;
		prismIndices[indiceIndex + 2] = currentIndice;

		prismIndices[indiceIndex + 3] = currentIndice + numberOfSides + 1;
		prismIndices[indiceIndex + 4] = currentIndice + 1;
		prismIndices[indiceIndex + 5] = currentIndice;
		currentIndice++;
	}

	prismIndices[indiceIndex++] = (numberOfSides * 2) - 1;
	prismIndices[indiceIndex++] = numberOfSides;
	prismIndices[indiceIndex++] = numberOfSides - 1;
								  
	prismIndices[indiceIndex++] = numberOfSides;
	prismIndices[indiceIndex++] = 0;
	prismIndices[indiceIndex] = numberOfSides - 1;

	/* Model size stuff */

	prismSizes.edges = prismEdges.size()/2;
	prismSizes.faces = numberOfSides + 2;
	prismSizes.indices = prismIndices.size();
	prismSizes.vertices = numberOfSides * 2;

	//Tells the renderer about groups of triangles for each face,
	//For example a 16 sides polygon has 14 triangles for the front and another 14 for the back,
	//and 2 triangles per side face, so 2 * 16, it would be listed like 14, 14, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
	prismSizes.indicePairs.push_back(numberOfSides - 2);
	prismSizes.indicePairs.push_back(numberOfSides - 2);
	for (int indicePairIndex = 0; indicePairIndex < numberOfSides; indicePairIndex++) {
		prismSizes.indicePairs.push_back(2);
	}
}


//This function takes a Point3D, a rotation value and returns a rotated Point3D, it rotates on the x axis
Point3D rotateXAxis(Point3D& original, double rotation) {
	Point3D copy;
	copy.x = original.x;
	copy.y = cos(rotation) * original.y - sin(rotation) * original.z;
	copy.z = sin(rotation) * original.y + cos(rotation) * original.z;
	return copy;
}

//This function takes a Point3D, a rotation value and returns a rotated Point3D, it rotates on the y axis
Point3D rotateYAxis(Point3D& original, double rotation) {
	Point3D copy;
	copy.x = cos(rotation) * original.x + sin(rotation) * original.z;
	copy.y = original.y;
	copy.z = -sin(rotation) * original.x + cos(rotation) * original.z;
	return copy;
}

//This function takes a Point3D, a rotation value and returns a rotated Point3D, it rotates on the z axis
Point3D rotateZAxis(Point3D& original, double rotation) {
	Point3D copy;
	copy.x = cos(rotation) * original.x - sin(rotation) * original.y;
	copy.y = sin(rotation) * original.x + cos(rotation) * original.y;
	copy.z = original.z;
	return copy;
}

//Copies a matrix from one var to another
void copyMatrix(Point3D& original, Point3D& copy) {
	copy.x = original.x;
	copy.y = original.y;
	copy.z = original.z;
}

void sortEdges(std::vector<int> edges, std::vector<Point3D> projectedPointWithZ, std::vector<EdgeWithZ>& arrayOfEdgesWithZ, ModelSizes modelSize, std::vector<unsigned char> edgeColours)
{
	EdgeWithZ temp;

	for (int i = 0; i < modelSize.edges; i++)
	{
		int colourIndex = (i * 3) % edgeColours.size();

		temp.p1 = edges[i * 2];
		temp.p2 = edges[(i * 2) + 1];
		temp.r = edgeColours[colourIndex];
		temp.g = edgeColours[colourIndex + 1];
		temp.b = edgeColours[colourIndex + 2];

		temp.z = projectedPointWithZ[edges[i * 2]].z;
		temp.z += projectedPointWithZ[edges[(i * 2) + 1]].z;
		temp.z /= 2;

		arrayOfEdgesWithZ.push_back(temp);
	}

	int i, j;
	bool swapped;
	for (i = 0; i < modelSize.edges - 1; i++) {
		swapped = false;
		for (j = 0; j < modelSize.edges - i - 1; j++) {
			if (arrayOfEdgesWithZ[j].z > arrayOfEdgesWithZ[j + 1].z) {
				EdgeWithZ temp = arrayOfEdgesWithZ[j + 1];
				arrayOfEdgesWithZ[j + 1] = arrayOfEdgesWithZ[j];
				arrayOfEdgesWithZ[j] = temp;
				swapped = true;
			}
		}

		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}
}

Point3D multiplyVertex(Point3D xAxis, Point3D yAxis, Point3D zAxis) {
	Point3D temp;
	temp.x = xAxis.x * yAxis.x * zAxis.x;
	temp.y = xAxis.y * yAxis.y * zAxis.y;
	temp.z = xAxis.z * yAxis.z * zAxis.z;
	return temp;
}

Point3D rotateAllDirection(Point3D point, double rotation) {
	Point3D temp = point;
	temp = rotateXAxis(temp, rotation);
	temp = rotateYAxis(temp, rotation);
	temp = rotateZAxis(temp, rotation);
	return temp;
}

void calculateObjectProjection(std::vector<Point3D>& projectedPointWithZ, double rotation, std::vector<Point3D> model, ModelSizes modelSize, Point3D positionShift, ProgramSettings programSettings) {
	//Gets the time now
	auto time1 = std::chrono::high_resolution_clock::now();

	std::vector<Point3D> calculatedVertexCoordinateArray = model;


	for (int vertexIndex = 0; vertexIndex < model.size(); vertexIndex++) {
		calculatedVertexCoordinateArray[vertexIndex].x += positionShift.x;
		calculatedVertexCoordinateArray[vertexIndex].y += positionShift.y;
		calculatedVertexCoordinateArray[vertexIndex].z += positionShift.z;

		Point3D temp = calculatedVertexCoordinateArray[vertexIndex];

		temp = rotateXAxis(temp, xRotation * degreesToRads);
		temp = rotateYAxis(temp, yRotation * degreesToRads);
		temp = rotateZAxis(temp, zRotation * degreesToRads);

		if (programSettings.projectionType == 0) {
			temp = PerspectiveProjection(temp);
		}
		else {
			temp = OrthographicProjection(temp);
		}

		projectedPointWithZ.push_back(temp);
	}

	auto time2 = std::chrono::high_resolution_clock::now();

	auto time = time2 - time1;
}

void renderModelByEdges(std::vector<Point3D> projectedPointWithZ, std::vector<int> edges, std::vector<EdgeWithZ> arrayOfEdgesWithZ, ModelSizes modelSize, std::vector<unsigned char> edgeColours) {
	unsigned char colour1 = edgeColours[0];
	unsigned char colour2 = edgeColours[1];
	unsigned char colour3 = edgeColours[2];
	int innerIndex = 0;

	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	for (int faceIndex = 0; faceIndex < modelSize.edges; faceIndex++) {
		int colourIndex = (faceIndex * 3) % edgeColours.size();

		colour1 = edgeColours[colourIndex];
		colour2 = edgeColours[colourIndex + 1];
		colour3 = edgeColours[colourIndex + 2];

		SDL_SetRenderDrawColor(gRenderer, colour1, colour2, colour3, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLineF(gRenderer, projectedPointWithZ[arrayOfEdgesWithZ[faceIndex].p1].x, projectedPointWithZ[arrayOfEdgesWithZ[faceIndex].p1].y, projectedPointWithZ[arrayOfEdgesWithZ[faceIndex].p2].x, projectedPointWithZ[arrayOfEdgesWithZ[faceIndex].p2].y);
		//SDL_RenderPresent(gRenderer);
	}
}

void renderModel(double rotation, std::vector<Point3D> model, std::vector<int> indicies, std::vector<int> edges, ModelSizes modelSize, std::vector<unsigned char> faceColours, std::vector<unsigned char> edgeColours, ProgramSettings programSettings, Point3D positionShift) {

	std::vector<Point3D> projectedPointWithZ;

	calculateObjectProjection(projectedPointWithZ, rotation, model, modelSize, positionShift, programSettings);

	if (programSettings.renderByFaces == 1) {
		std::vector<Indice> IndiceArray;

		sortFaces(indicies, projectedPointWithZ, IndiceArray, modelSize, faceColours);

		renderModelByIndices(projectedPointWithZ, indicies, IndiceArray, modelSize, faceColours);
	}

	if (programSettings.renderByEdges == 1) {
		std::vector<EdgeWithZ> arrayOfEdgesWithZ;

		sortEdges(edges, projectedPointWithZ, arrayOfEdgesWithZ, modelSize, edgeColours);

		renderModelByEdges(projectedPointWithZ, edges, arrayOfEdgesWithZ, modelSize, edgeColours);

	}
}

//This function sorts the faces by their corresponding furthest z value
void sortFaces(std::vector<int> indicies, std::vector<Point3D> projectedPointWithZ, std::vector<Indice>& arrayOfFaceIndicesWithZ, ModelSizes modelSize, std::vector<unsigned char> faceColours)
{
	Indice temp;
	int colourIndex = 0;
	int zAdditionIndex = 0;
	int indicePairIndex = 0;
	std::vector<float> tempZArray(modelSize.indicePairs.size());
	std::fill(tempZArray.begin(), tempZArray.end(), 0);

	for (int i = 0; i < modelSize.indices / 3; i++)
	{
		if (zAdditionIndex == 0) {
			zAdditionIndex = modelSize.indicePairs[indicePairIndex++];
		}

		temp.p1 = indicies[i * 3];
		temp.p2 = indicies[(i * 3) + 1];
		temp.p3 = indicies[(i * 3) + 2];

		temp.p1r = faceColours[colourIndex++];
		temp.p1g = faceColours[colourIndex++];
		temp.p1b = faceColours[colourIndex++];

		temp.p2r = faceColours[colourIndex++];
		temp.p2g = faceColours[colourIndex++];
		temp.p2b = faceColours[colourIndex++];

		temp.p3r = faceColours[colourIndex++];
		temp.p3g = faceColours[colourIndex++];
		temp.p3b = faceColours[colourIndex++];

		tempZArray[indicePairIndex - 1] += projectedPointWithZ[indicies[i * 3]].z;
		tempZArray[indicePairIndex - 1] += projectedPointWithZ[indicies[(i * 3) + 1]].z;
		tempZArray[indicePairIndex - 1] += projectedPointWithZ[indicies[(i * 3) + 2]].z;

		/*temp.z = projectedPointWithZ[indicies[i * 3]].z;
		temp.z += projectedPointWithZ[indicies[(i * 3) + 1]].z;
		temp.z += projectedPointWithZ[indicies[(i * 3) + 2]].z;
		temp.z /= 3;*/

		zAdditionIndex--;

		arrayOfFaceIndicesWithZ.push_back(temp);
	}

	for (int tempZIndex = 0; tempZIndex < modelSize.indicePairs.size(); tempZIndex++) {
		tempZArray[tempZIndex] /= modelSize.indicePairs[tempZIndex];
	}

	int index = 0;

	for (int i = 0; i < modelSize.indices / 3; i++)
	{
		if (zAdditionIndex == 0) {
			zAdditionIndex = modelSize.indicePairs[index++];
		}

		arrayOfFaceIndicesWithZ[i].z = tempZArray[index - 1];

		zAdditionIndex--;
	}


	int i, j;
	bool swapped;
	for (i = 0; i < modelSize.indices / 3 - 1; i++) {
		swapped = false;
		for (j = 0; j < modelSize.indices / 3 - i - 1; j++) {
			if (arrayOfFaceIndicesWithZ[j].z > arrayOfFaceIndicesWithZ[j + 1].z) {
				Indice temp = arrayOfFaceIndicesWithZ[j + 1];
				arrayOfFaceIndicesWithZ[j + 1] = arrayOfFaceIndicesWithZ[j];
				arrayOfFaceIndicesWithZ[j] = temp;
				swapped = true;
			}
		}

		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}
}

void renderModelByIndices(std::vector<Point3D> projectedPointWithZ, std::vector<int> cubeIndicesArr, std::vector<Indice> arrayOfFaceIndicesWithZ, ModelSizes cubeSizes, std::vector<unsigned char> cubeFaceColours) {
	int innerIndex = 0;
	for (int faceIndex = 0; faceIndex < cubeSizes.indices / 3; faceIndex++) {


		/*std::vector< SDL_Vertex > tri =
		{
			{ SDL_FPoint{ projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p1].x, projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p1].y}, SDL_Color{arrayOfFaceIndicesWithZ[faceIndex].p1r, arrayOfFaceIndicesWithZ[faceIndex].p1g, arrayOfFaceIndicesWithZ[faceIndex].p1b, 255}, SDL_FPoint{0},},
			{ SDL_FPoint{ projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p2].x, projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p2].y}, SDL_Color{arrayOfFaceIndicesWithZ[faceIndex].p2r, arrayOfFaceIndicesWithZ[faceIndex].p2g, arrayOfFaceIndicesWithZ[faceIndex].p2b, 255}, SDL_FPoint{0},},
			{ SDL_FPoint{ projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p3].x, projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p3].y}, SDL_Color{arrayOfFaceIndicesWithZ[faceIndex].p3r, arrayOfFaceIndicesWithZ[faceIndex].p3g, arrayOfFaceIndicesWithZ[faceIndex].p3b, 255}, SDL_FPoint{0},},
		};*/

		std::vector< SDL_Vertex > tri =
		{
			{ SDL_FPoint{ projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p1].x, projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p1].y}, SDL_Color{cubeFaceColours[0], cubeFaceColours[1], cubeFaceColours[2], 255}, SDL_FPoint{0},},
			{ SDL_FPoint{ projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p2].x, projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p2].y}, SDL_Color{cubeFaceColours[0], cubeFaceColours[1], cubeFaceColours[2], 255}, SDL_FPoint{0},},
			{ SDL_FPoint{ projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p3].x, projectedPointWithZ[arrayOfFaceIndicesWithZ[faceIndex].p3].y}, SDL_Color{cubeFaceColours[0], cubeFaceColours[1], cubeFaceColours[2], 255}, SDL_FPoint{0},},
		};

		SDL_RenderGeometry(gRenderer, gTexture, tri.data(), (int)tri.size(), nullptr, 0);
		//SDL_RenderPresent(gRenderer);
	}
}

void randomizeFaceColours(std::vector<unsigned char>& faceColours)
{

	//Gets the time now
	auto time1 = std::chrono::high_resolution_clock::now();


	//#pragma omp parallel for
	for (int colourIndex = 0; colourIndex < faceColours.size(); colourIndex++) {
		faceColours[colourIndex] = std::rand() % 256;
	}

	//Gets the time now
	auto time2 = std::chrono::high_resolution_clock::now();

	auto time = time2 - time1;
}

void randomizeEdgeColours(std::vector<unsigned char>& edgeColours)
{
	for (int colourIndex = 0; colourIndex < edgeColours.size(); colourIndex++) {
		edgeColours[colourIndex] = std::rand() % 256;
	}
}
