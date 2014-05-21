// This file declares the IApplicationDebugger Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIApplicationDebugger : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR_ERRORINFO(PyIApplicationDebugger, IID_IApplicationDebugger);
	static IApplicationDebugger *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *QueryAlive(PyObject *self, PyObject *args);
	static PyObject *CreateInstanceAtDebugger(PyObject *self, PyObject *args);
	static PyObject *onDebugOutput(PyObject *self, PyObject *args);
	static PyObject *onHandleBreakPoint(PyObject *self, PyObject *args);
	static PyObject *onClose(PyObject *self, PyObject *args);
	static PyObject *onDebuggerEvent(PyObject *self, PyObject *args);

protected:
	PyIApplicationDebugger(IUnknown *pdisp);
	~PyIApplicationDebugger();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGApplicationDebugger : public PyGatewayBase, public IApplicationDebugger
{
protected:
	PyGApplicationDebugger(PyObject *instance) : PyGatewayBase(instance) { ; }
	PYGATEWAY_MAKE_SUPPORT(PyGApplicationDebugger, IApplicationDebugger, IID_IApplicationDebugger)

	// IApplicationDebugger
	STDMETHOD(QueryAlive)(
		void);

	STDMETHOD(CreateInstanceAtDebugger)(
		REFCLSID rclsid,
		IUnknown __RPC_FAR * pUnkOuter,
		DWORD dwClsContext,
		REFIID riid,
		IUnknown __RPC_FAR *__RPC_FAR * ppvObject);

	STDMETHOD(onDebugOutput)(
		LPCOLESTR pstr);

	STDMETHOD(onHandleBreakPoint)(
		IRemoteDebugApplicationThread __RPC_FAR * prpt,
		BREAKREASON br,
		IActiveScriptErrorDebug __RPC_FAR *pError);

	STDMETHOD(onClose)(
		void);

	STDMETHOD(onDebuggerEvent)(
		REFIID riid,
		IUnknown *punk);
};
