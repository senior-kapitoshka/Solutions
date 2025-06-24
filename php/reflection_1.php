function get_info($fn) {
  $rf = new ReflectionFunction($fn);
  
  return [
    $rf->getNumberOfParameters(),
    $rf->getNumberOfRequiredParameters(),
    $rf->hasReturnType(),
    $rf->isClosure(),
    $rf->isInternal(),
    $rf->isUserDefined()
  ];
}