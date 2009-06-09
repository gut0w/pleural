function loadXMLDoc(dname) 
{
try //Internet Explorer
  {
  xmlDoc=new ActiveXObject("Microsoft.XMLDOM");
  }
catch(e)
  {
  try //Firefox, Mozilla, Opera, etc.
    {
    xmlDoc=document.implementation.createDocument("","",null);
    }
  catch(e) {alert(e.message)}
  }
try 
  {
  xmlDoc.async=false;
  xmlDoc.load(dname);
  return(xmlDoc);
  }
catch(e) {alert(e.message)}
return(null);
}

function handler() {
 if(this.readyState == 4 && this.status == 200) {
  // so far so good
  if(this.responseXML != null && this.responseXML.getElementById('test').firstChild.data)
     // success!
   test(this.responseXML.getElementById('test').firstChild.data);
  else
   test(null);
 } else if (this.readyState == 4 && this.status != 200) {
  // fetched the wrong page or network error...
  test(null);
 }
}

function log(message) {
 var client = new XMLHttpRequest();
 client.open("POST", "/log");
 client.setRequestHeader("Content-Type", "text/plain;charset=UTF-8");
 client.send(message);
}