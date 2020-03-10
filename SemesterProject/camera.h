#ifndef camera_h
#define camera_h

#include <dshow.h>
#include <iostream>
#include <Windows.h>
#include <strmif.h>
#include <ks.h>
#include <Ksmedia.h>

using namespace std;

//typedef enum tagCameraControlProperty { //enum typedef to control the camera's parameters
//						//Constants
//	CameraControl_Pan,	//Specifies the camera's pan setting, in degrees. Values range from –180 to +180, with the default set to zero. Positive values are clockwise from the origin (the camera rotates clockwise when viewed from above), and negative values are counterclockwise from the origin.
//	CameraControl_Tilt, //Specifies the camera's tilt setting, in degrees. Values range from –180 to +180, with the default set to zero. Positive values point the imaging plane up, and negative values point the imaging plane down.
//	CameraControl_Roll, //Specifies the camera's roll setting, in degrees. Values range from –180 to +180, with the default set to zero. Positive values cause a clockwise rotation of the camera along the image-viewing axis, and negative values cause a counterclockwise rotation of the camera.
//	CameraControl_Zoom, //Specifies the camera's zoom setting, in millimeters. Values range from 10 to 600, and the default is specific to the device.
//	CameraControl_Exposure, //Specifies the exposure setting, in log base 2 seconds. In other words, for values less than zero, the exposure time is 1/2^n seconds, and for values zero or above, the exposure time is 2^n seconds. For example:
//	CameraControl_Iris,
//	CameraControl_Focus
//} CameraControlProperty;

//typedef enum tagCameraControlFlags { //selector between auto and manual control of the camera
//	CameraControl_Flags_Auto,
//	CameraControl_Flags_Manual
//} CameraControlFlags;

class camera
{
public:
	camera();
	~camera();
	//void takePic();
	//HRESULT CoCreateInstance(
	//	REFCLSID  rclsid, //use: CLSID_SystemDeviceEnum
	//	LPUNKNOWN pUnkOuter,
	//	DWORD     dwClsContext,
	//	REFIID    riid,
	//	LPVOID* ppv
	//);

	HRESULT InitCaptureGraphBuilder(
		IGraphBuilder** ppGraph,  // Receives the pointer.
		ICaptureGraphBuilder2** ppBuild  // Receives the pointer.
	);
	HRESULT deviceEnum();
	//HRESULT Get(
	//	long Property,
	//	long* lValue,
	//	long* Flags
	//);
	//HRESULT GetRange(
	//	long Property,
	//	long* pMin,
	//	long* pMax,
	//	long* pSteppingDelta,
	//	long* pDefault,
	//	long* pCapsFlags
	//);
	//HRESULT Set(
	//	long Property,
	//	long lValue,
	//	long Flags
	//);
	void captureGraphBuilder();
private:

};




#endif // !camera_h