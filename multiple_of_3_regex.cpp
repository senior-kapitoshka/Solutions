const std::string multiple_of_3_regex = "(0|1((01*0)*1))*";

////////////////

const std::string multiple_of_3_regex = 
  R"re(^(?:(?:(?:0*1)(?:10*1)*0)(?:(?:0(?:10*1)*0)|1)*(?:0(?:10*1)*(?:10*)))|(?:(?:(?:0*1)(?:10*1)*(?:10*))|0+)$)re";
  /////////////////
  const std::string multiple_of_3_regex = "^0$|^1(01*0)*1$|(^0|1(01*0)*1)(0|1(01*0)*1)*(0|1(01*0)*1)$";