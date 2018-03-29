# Sketch AnimaAPI

* Sketch AnimaAPI is an Objective C class that can be used to interact with the [Anima Toolkit for Sketch](https://www.animaapp.com).
* Anima Toolkit for Sketch enables use of [Auto-Layout](https://animaapp.github.io/docs/v1/auto-layout/), [Stacks](https://animaapp.github.io/docs/v1/auto-layout/12-stacks-flexbox.html) and other features that enhance Sketch's functionality.
* By using `AnimaAPI` methods, anyone can check if a document has Anima properties in it, and strip them if needed.

## How to use with Cocoascript
```
@import "MochaJSDelegate"

var document = context.document

var delegate = new MochaJSDelegate()

COScript.currentCOScript().setShouldKeepAround_(true);
delegate.setHandlerForSelector("didFinishPreparingForExport:outputPath:", function(document, outputPath) {
  // log(outputURL) (do your thing)
  document.close()
  COScript.currentCOScript().setShouldKeepAround_(false);
});

AnimaAPI.prepareForExportWithInputDocument_delegate(document, delegate.getClassInstance())
```

## How to use with Objective C
```

```
