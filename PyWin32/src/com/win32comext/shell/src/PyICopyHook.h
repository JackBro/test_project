// This file declares the ICopyHook Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyICopyHookA : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyICopyHookA);
	static ICopyHookA *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *CopyCallback(PyObject *self, PyObject *args);

protected:
	PyICopyHookA(IUnknown *pdisp);
	~PyICopyHookA();
};

class PyICopyHookW : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyICopyHookW);
	static ICopyHookW *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *CopyCallback(PyObject *self, PyObject *args);

protected:
	PyICopyHookW(IUnknown *pdisp);
	~PyICopyHookW();
};

// ---------------------------------------------------
//
// Gateway Declaration

class PyGCopyHookA : public PyGatewayBase, public ICopyHookA
{
protected:
	PyGCopyHookA(PyObject *instance) : PyGatewayBase(instance) { ; }
	PYGATEWAY_MAKE_SUPPORT2(PyGCopyHookA, ICopyHookA, IID_IShellCopyHookA, PyGatewayBase)

	// ICopyHook
	STDMETHOD_(UINT, CopyCallback)(
		HWND hwnd,
		UINT wFunc,
		UINT wFlags,
		LPCSTR srcFile,
		DWORD srcAttribs,
		LPCSTR destFile,
		DWORD destAttribs);
};

class PyGCopyHookW : public PyGatewayBase, public ICopyHookW
{
protected:
	PyGCopyHookW(PyObject *instance) : PyGatewayBase(instance) { ; }
	PYGATEWAY_MAKE_SUPPORT2(PyGCopyHookW, ICopyHookW, IID_IShellCopyHookW, PyGatewayBase)

	// ICopyHook
	STDMETHOD_(UINT, CopyCallback)(
		HWND hwnd,
		UINT wFunc,
		UINT wFlags,
		LPCWSTR srcFile,
		DWORD srcAttribs,
		LPCWSTR destFile,
		DWORD destAttribs);
};
