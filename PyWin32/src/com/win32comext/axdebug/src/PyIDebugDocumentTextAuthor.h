// This file declares the IDebugDocumentTextAuthor Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIDebugDocumentTextAuthor : public PyIDebugDocumentText
{
public:
	MAKE_PYCOM_CTOR_ERRORINFO(PyIDebugDocumentTextAuthor, IID_IDebugDocumentTextAuthor);
	static IDebugDocumentTextAuthor *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *InsertText(PyObject *self, PyObject *args);
	static PyObject *RemoveText(PyObject *self, PyObject *args);
	static PyObject *ReplaceText(PyObject *self, PyObject *args);

protected:
	PyIDebugDocumentTextAuthor(IUnknown *pdisp);
	~PyIDebugDocumentTextAuthor();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGDebugDocumentTextAuthor : public PyGDebugDocumentText, public IDebugDocumentTextAuthor
{
protected:
	PyGDebugDocumentTextAuthor(PyObject *instance) : PyGDebugDocumentText(instance) { ; }
	PYGATEWAY_MAKE_SUPPORT2(PyGDebugDocumentTextAuthor, IDebugDocumentTextAuthor, IID_IDebugDocumentTextAuthor, PyGDebugDocumentText)

	// IDebugDocumentInfo
	STDMETHOD(GetName)(  
		DOCUMENTNAMETYPE dnt,  
		BSTR *pbstrName);  
	STDMETHOD(GetDocumentClassId)(
		CLSID *pclsidDocument);

	// IDebugDocument

	// IDebugDocumentText
	STDMETHOD(GetDocumentAttributes)(
		TEXT_DOC_ATTR __RPC_FAR * ptextdocattr);

	STDMETHOD(GetSize)(
		ULONG __RPC_FAR * pcNumLines,
		ULONG __RPC_FAR * pcNumChars);

	STDMETHOD(GetPositionOfLine)(
		ULONG cLineNumber,
		ULONG __RPC_FAR * pcCharacterPosition);

	STDMETHOD(GetLineOfPosition)(
		ULONG cCharacterPosition,
		ULONG __RPC_FAR * pcLineNumber,
		ULONG __RPC_FAR * pcCharacterOffsetInLine);

	STDMETHOD(GetText)(
		ULONG cCharacterPosition,
		WCHAR __RPC_FAR * pcharText,
		SOURCE_TEXT_ATTR __RPC_FAR * pstaTextAttr,
		ULONG __RPC_FAR * pcNumChars,
		ULONG cMaxChars);

	STDMETHOD(GetPositionOfContext)(
		IDebugDocumentContext __RPC_FAR * psc,
		ULONG __RPC_FAR * pcCharacterPosition,
		ULONG __RPC_FAR * cNumChars);

	STDMETHOD(GetContextOfPosition)(
		ULONG cCharacterPosition,
		ULONG cNumChars,
		IDebugDocumentContext __RPC_FAR *__RPC_FAR * ppsc);


	// IDebugDocumentTextAuthor
	STDMETHOD(InsertText)(
		ULONG cCharacterPosition,
		ULONG cNumToInsert,
		OLECHAR __RPC_FAR pcharText[]);

	STDMETHOD(RemoveText)(
		ULONG cCharacterPosition,
		ULONG cNumToRemove);

	STDMETHOD(ReplaceText)(
		ULONG cCharacterPosition,
		ULONG cNumToReplace,
		OLECHAR __RPC_FAR pcharText[]);

};
