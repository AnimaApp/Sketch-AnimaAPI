# Sketch-AnimaAPI

```
@import "MochaJSDelegate"
COScript.currentCOScript().setShouldKeepAround_(true);
var document = context.document
var delegate = new MochaJSDelegate()
delegate.setHandlerForSelector("didFinishPreparingForExport:outputURL:", function(document, outputURL){
  log(outputURL)
  document.close()
  COScript.currentCOScript().setShouldKeepAround_(false);
});

AnimaAPI.prepareForExportWithInputDocument_delegate(document, delegate.getClassInstance())
```
