#pragma once

#define WINDOW_WIDTH 1280

#define WINDOW_HEIGH 720

#if defined(_WIN64)
#define FRACTAL_WINDOW
#elif defined(__linux__)
#define FRACTEL_LINUX
#elif defined(__APPLE__)
#define FRACTAL_APPLE
#else
	#error Not Supported Platform!
#endif

#define GUISTYLE 1
#define MAX_FPS 70
#define DEBUG true

#ifdef FR_WINDOW
	// window platform related stuff
    #include <windows.h>
#endif

#ifdef FR_LINUX
	// linux platform related stuff
    #include <bits/stdc++.h>
#endif

#ifdef FR_APPLE
	// mac platform related stuff
#endif