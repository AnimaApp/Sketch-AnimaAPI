# Sketch AnimaAPI

* Sketch AnimaAPI is an Objective C class that can be used to interact with the [Anima Toolkit for Sketch](https://www.animaapp.com).
* Anima Toolkit for Sketch enables use of [Auto-Layout](https://animaapp.github.io/docs/v1/auto-layout/), [Stacks](https://animaapp.github.io/docs/v1/auto-layout/12-stacks-flexbox.html) and other features that enhance Sketch's functionality.
* By using `AnimaAPI` methods, anyone can check if a document has Anima properties in it, and strip them if needed.
* Stripping Anima's properties is done on a duplicated document to prevent modifying the original document.

## How to use with Cocoascript
```
@import "MochaJSDelegate"

function isAnimaInstalled () {
  try {
    AnimaAPI
    return true
  } catch(e) {
    return false
  }
}

if (!isAnimaInstalled) {
  log("Anima Toolkit is not installed or has an old version that doesn't support AnimaAPI.")
  return
}

var document = context.document
var documentHasAnimaProperties = AnimaAPI.doesDocumentHaveAnimaProperties(document)
if (!documentHasAnimaProperties) {
  log("Document is not using Anima Toolkit.")
  return
}

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
if ( ! [AnimaAPI class]) {
  NSLog(@"Anima Toolkit is not installed or has an old version that doesn't support AnimaAPI");
}

if ( ! [AnimaAPI doesDocumentHaveAnimaProperties:document]) {
  NSLog(@"Document is not using Anima Toolkit.");
}

[AnimaAPI prepareForExportWithInputDocument:originalDocument outputPath:nil completionBlock:^(NSDocument *outputDocument, NSError *error) {
    // do your thing with the stripped document
    [outputDocument close];
}];
```
