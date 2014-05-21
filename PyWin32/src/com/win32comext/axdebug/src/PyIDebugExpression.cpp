// This file implements the IDebugExpression Interface and Gateway for Python.
// Generated by makegw.py

#include "stdafx.h"
#include "PythonCOM.h"
#include "PythonCOMServer.h"
#include "PyIDebugExpression.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIDebugExpression::PyIDebugExpression(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIDebugExpression::~PyIDebugExpression()
{
}

/* static */ IDebugExpression *PyIDebugExpression::GetI(PyObject *self)
{
	return (IDebugExpression *)PyIUnknown::GetI(self);
}

// @pymethod |PyIDebugExpression|Start|Description of Start.
PyObject *PyIDebugExpression::Start(PyObject *self, PyObject *args)
{
	IDebugExpression *pIDE = GetI(self);
	if ( pIDE == NULL )
		return NULL;
	// @pyparm <o PyIDebugExpressionCallBack>|pdecb||Description for pdecb
	PyObject *obpdecb;
	IDebugExpressionCallBack *pdecb;
	if ( !PyArg_ParseTuple(args, "O:Start", &obpdecb) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_InterfaceFromPyInstanceOrObject(obpdecb, IID_IDebugExpressionCallBack, (void **)&pdecb, FALSE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDE->Start( pdecb );
	pdecb->Release();
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIDebugExpression|Abort|Description of Abort.
PyObject *PyIDebugExpression::Abort(PyObject *self, PyObject *args)
{
	IDebugExpression *pIDE = GetI(self);
	if ( pIDE == NULL )
		return NULL;
	if ( !PyArg_ParseTuple(args, ":Abort") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDE->Abort( );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIDebugExpression|QueryIsComplete|Description of QueryIsComplete.
PyObject *PyIDebugExpression::QueryIsComplete(PyObject *self, PyObject *args)
{
	IDebugExpression *pIDE = GetI(self);
	if ( pIDE == NULL )
		return NULL;
	if ( !PyArg_ParseTuple(args, ":QueryIsComplete") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDE->QueryIsComplete( );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIDebugExpression|GetResultAsString|Description of GetResultAsString.
PyObject *PyIDebugExpression::GetResultAsString(PyObject *self, PyObject *args)
{
	IDebugExpression *pIDE = GetI(self);
	if ( pIDE == NULL )
		return NULL;
	HRESULT phrResult;
	BSTR pbstrResult;
	if ( !PyArg_ParseTuple(args, ":GetResultAsString") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDE->GetResultAsString( &phrResult, &pbstrResult );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);
	PyObject *obpbstrResult;

	obpbstrResult = MakeBstrToObj(pbstrResult);
	PyObject *pyretval = Py_BuildValue("iO", phrResult, obpbstrResult);
	Py_XDECREF(obpbstrResult);
	SysFreeString(pbstrResult);
	return pyretval;
}

// @pymethod |PyIDebugExpression|GetResultAsDebugProperties|Description of GetResultAsDebugProperty.
PyObject *PyIDebugExpression::GetResultAsDebugProperty(PyObject *self, PyObject *args)
{
	IDebugExpression *pIDE = GetI(self);
	if ( pIDE == NULL )
		return NULL;
	HRESULT phrResult;
	IDebugProperty *pdp;
	if ( !PyArg_ParseTuple(args, ":GetResultAsDebugProperty") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDE->GetResultAsDebugProperty( &phrResult, &pdp );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self,hr);
	PyObject *obDebugProperties = PyCom_PyObjectFromIUnknown(pdp, IID_IDebugProperty, FALSE /* AddRef? */);
	return Py_BuildValue("iN", phrResult, obDebugProperties);
}

// @object PyIDebugExpression|Description of the interface
static struct PyMethodDef PyIDebugExpression_methods[] =
{
	{ "Start", PyIDebugExpression::Start, 1 }, // @pymeth Start|Description of Start
	{ "Abort", PyIDebugExpression::Abort, 1 }, // @pymeth Abort|Description of Abort
	{ "QueryIsComplete", PyIDebugExpression::QueryIsComplete, 1 }, // @pymeth QueryIsComplete|Description of QueryIsComplete
	{ "GetResultAsString", PyIDebugExpression::GetResultAsString, 1 }, // @pymeth GetResultAsString|Description of GetResultAsString
	{ "GetResultAsDebugProperty", PyIDebugExpression::GetResultAsDebugProperty, 1 }, // @pymeth GetResultAsDebugProperties|Description of GetResultAsDebugProperties
	{ NULL }
};

PyComTypeObject PyIDebugExpression::type("PyIDebugExpression",
		&PyIUnknown::type,
		sizeof(PyIDebugExpression),
		PyIDebugExpression_methods,
		GET_PYCOM_CTOR(PyIDebugExpression));
// ---------------------------------------------------
//
// Gateway Implementation

STDMETHODIMP PyGDebugExpression::Start(
		/* [in] */ IDebugExpressionCallBack __RPC_FAR * pdecb)
{
	PY_GATEWAY_METHOD;
	PyObject *obpdecb;
	obpdecb = PyCom_PyObjectFromIUnknown(pdecb, IID_IDebugExpressionCallBack, TRUE);
	HRESULT hr=InvokeViaPolicy("Start", NULL, "O", obpdecb);
	Py_XDECREF(obpdecb);
	return hr;
}

STDMETHODIMP PyGDebugExpression::Abort(
		void)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("Abort", NULL);
	return hr;
}

STDMETHODIMP PyGDebugExpression::QueryIsComplete(
		void)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("QueryIsComplete", NULL);
	return hr;
}

STDMETHODIMP PyGDebugExpression::GetResultAsString(
		/* [out] */ HRESULT __RPC_FAR * phrResult,
		/* [out] */ BSTR __RPC_FAR * pbstrResult)
{
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetResultAsString", &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obpbstrResult;
	if (!PyArg_ParseTuple(result, "iO" , phrResult, &obpbstrResult)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_BstrFromPyObject(obpbstrResult, pbstrResult, TRUE)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGDebugExpression::GetResultAsDebugProperty(
		/* [out] */ HRESULT __RPC_FAR * phrResult,
		/* [out] */ IDebugProperty __RPC_FAR * __RPC_FAR * ppdp)
{
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetResultAsDebugProperty", &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obdp;
	if (!PyArg_ParseTuple(result, "iO" , phrResult, &obdp)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	if (!PyCom_InterfaceFromPyInstanceOrObject(obdp, IID_IDebugProperty, (void **)ppdp, FALSE))
		return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

