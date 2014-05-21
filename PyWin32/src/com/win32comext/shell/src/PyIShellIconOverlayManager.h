// This file declares the IShellIconOverlayManager Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIShellIconOverlayManager : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyIShellIconOverlayManager);
	static IShellIconOverlayManager *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *GetFileOverlayInfo(PyObject *self, PyObject *args);
	static PyObject *GetReservedOverlayInfo(PyObject *self, PyObject *args);
	static PyObject *RefreshOverlayImages(PyObject *self, PyObject *args);
	static PyObject *LoadNonloadedOverlayIdentifiers(PyObject *self, PyObject *args);
	static PyObject *OverlayIndexFromImageIndex(PyObject *self, PyObject *args);

protected:
	PyIShellIconOverlayManager(IUnknown *pdisp);
	~PyIShellIconOverlayManager();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGShellIconOverlayManager : public PyGatewayBase, public IShellIconOverlayManager
{
protected:
	PyGShellIconOverlayManager(PyObject *instance) : PyGatewayBase(instance) { ; }
	PYGATEWAY_MAKE_SUPPORT2(PyGShellIconOverlayManager, IShellIconOverlayManager, IID_IShellIconOverlayManager, PyGatewayBase)



	// IShellIconOverlayManager
	STDMETHOD(GetFileOverlayInfo)(
		LPCWSTR path,
		DWORD attrib,
		int __RPC_FAR * index,
		DWORD flags);

	STDMETHOD(GetReservedOverlayInfo)(
		LPCWSTR path,
		DWORD attrib,
		int __RPC_FAR * index,
		DWORD flags,
		int ireservedID);

	STDMETHOD(RefreshOverlayImages)(
		DWORD flags);

	STDMETHOD(LoadNonloadedOverlayIdentifiers)(
		void);

	STDMETHOD(OverlayIndexFromImageIndex)(
		int iImage,
		int __RPC_FAR * index,
		BOOL fAdd);

};
