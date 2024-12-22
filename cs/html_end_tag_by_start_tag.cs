namespace myjinxin
{
    using System;
  using System.Text.RegularExpressions;
    
    public class Kata
    {
        public string HtmlEndTagByStartTag(string ST){
          Regex rg=new Regex("^<([a-z]+)[\\w|\\W]*>$");
          Match m = rg.Match(ST);
          return "</"+m.Groups[1]+">";
        }
    }
}

////////////
namespace myjinxin
{
    using System;
    using System.Text.RegularExpressions;
    public class Kata
    {
        public string HtmlEndTagByStartTag(string StartTag){
          return Regex.Replace(Regex.Replace(StartTag," .*?>",">"),"^<","</");
        }
    }
}

/////////////
using System.Text.RegularExpressions;

public class Kata
{
  public string HtmlEndTagByStartTag(string StartTag)
  {
    return "</" + Regex.Match(StartTag, @"\w+") + ">";
  }
}

/////////////
namespace myjinxin
{
    using System;
    using System.Text.RegularExpressions;
    public class Kata
    {
        public string HtmlEndTagByStartTag(string StartTag){
          return "</" + Regex.Match(StartTag, @"\w+")+ ">";
          
          
        }
    }
}