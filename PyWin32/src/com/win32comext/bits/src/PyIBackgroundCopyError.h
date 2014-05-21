// This file declares the IBackgroundCopyError Interface for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIBackgroundCopyError : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyIBackgroundCopyError);
	static IBackgroundCopyError *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *GetError(PyObject *self, PyObject *args);
	static PyObject *GetFile(PyObject *self, PyObject *args);
	static PyObject *GetErrorDescription(PyObject *self, PyObject *args);
	static PyObject *GetErrorContextDescription(PyObject *self, PyObject *args);
	static PyObject *GetProtocol(PyObject *self, PyObject *args);

protected:
	PyIBackgroundCopyError(IUnknown *pdisp);
	~PyIBackgroundCopyError();
};
