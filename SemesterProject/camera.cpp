#include "camera.h"
camera::camera() {

}
camera::~camera() {

}
HRESULT camera::deviceEnum()
{
    // Create the System Device Enumerator.
    HRESULT hr;
    
    ICreateDevEnum* pSysDevEnum = NULL;
    hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
        IID_ICreateDevEnum, (void**)&pSysDevEnum);
    if (FAILED(hr))
    {
        cout << "Failed";
        return hr;
    }

    // Obtain a class enumerator for the video compressor category.
    IEnumMoniker* pEnumCat = NULL;
    hr = pSysDevEnum->CreateClassEnumerator(CLSID_VideoCompressorCategory, &pEnumCat, 0);

    if (hr == S_OK)
    {
        // Enumerate the monikers.
        IMoniker* pMoniker = NULL;
        ULONG cFetched;
        while (pEnumCat->Next(1, &pMoniker, &cFetched) == S_OK)
        {
            IPropertyBag* pPropBag;
            hr = pMoniker->BindToStorage(0, 0, IID_IPropertyBag,
                (void**)&pPropBag);
            if (SUCCEEDED(hr))
            {
                // To retrieve the filter's friendly name, do the following:
                VARIANT varName;
                VariantInit(&varName);
                hr = pPropBag->Read(L"FriendlyName", &varName, 0);
                if (SUCCEEDED(hr))
                {
                    cout << "hello"<< pPropBag->Read(L"FriendlyName", &varName, 0);
                    // Display the name in your UI somehow.
                }
                VariantClear(&varName);

                // To create an instance of the filter, do the following:
                IBaseFilter* pFilter;
                hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
                    (void**)&pFilter);
                // Now add the filter to the graph. 
                //Remember to release pFilter later.
                pPropBag->Release();
            }
            pMoniker->Release();
        }
        pEnumCat->Release();
    }
    pSysDevEnum->Release();

}
//HRESULT camera::Get(long Property, long* lValue, long* Flags)
//{
//   // return E_NOTIMPL;
//}
//HRESULT camera::GetRange( //gets the range and default value of the specified camera property.
//         long Property, 
//         long* pMin, 
//         long* pMax, 
//         long* pSteppingDelta, 
//         long* pDefault, 
//         long* pCapsFlags)
//{
////return 
//}
//HRESULT camera::Set(long Property, long lValue, long Flags)
//{
//    return NULL;
//}
void camera::captureGraphBuilder()
{
    IGraphBuilder* pGraph = NULL;
    ICaptureGraphBuilder2* pBuilder = NULL;

    // Create the Filter Graph Manager.
    HRESULT hr = CoCreateInstance(CLSID_FilterGraph, NULL,
        CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&pGraph);

    if (SUCCEEDED(hr))
    {
        // Create the Capture Graph Builder.
        hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL,
            CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2,
            (void**)&pBuilder);
        if (SUCCEEDED(hr))
        {
            pBuilder->SetFiltergraph(pGraph);
        }
    };
}
#include <windows.h>
#include <dshow.h>


HRESULT camera::InitCaptureGraphBuilder(
    IGraphBuilder** ppGraph,  // Receives the pointer.
    ICaptureGraphBuilder2** ppBuild  // Receives the pointer.
)
{
    if (!ppGraph || !ppBuild)
    {
        return E_POINTER;
    }
    IGraphBuilder* pGraph = NULL;
    ICaptureGraphBuilder2* pBuild = NULL;

    // Create the Capture Graph Builder.
    HRESULT hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL,
        CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2, (void**)&pBuild);
    if (SUCCEEDED(hr))
    {
        // Create the Filter Graph Manager.
        hr = CoCreateInstance(CLSID_FilterGraph, 0, CLSCTX_INPROC_SERVER,
            IID_IGraphBuilder, (void**)&pGraph);
        if (SUCCEEDED(hr))
        {
            // Initialize the Capture Graph Builder.
            pBuild->SetFiltergraph(pGraph);

            // Return both interface pointers to the caller.
            *ppBuild = pBuild;
            *ppGraph = pGraph; // The caller must release both interfaces.
            return S_OK;
        }
        else
        {
            pBuild->Release();
        }
    }
    return hr; // Failed
}