# Sketch AnimaAPI

* Sketch AnimaAPI is an Objective C class that can be used to interact with the Anima Toolkit for Sketch.
* Anima Toolkit for Sketch enables use of Auto-Layout, Stacks and other features that enhance Sketch's functionality.
* By using `AnimaAPI` methods, anyone can check if a document has Anima properties in it, and strip them if needed.

## How to use with Cocoascript
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

## How to use with Objective C
```

```
