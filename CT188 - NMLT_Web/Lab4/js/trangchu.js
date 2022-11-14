var d = new Date();
var ads = "Khách hàng có ngày sinh trong tháng "+d.getMonth()+"sẽ được tặng 2 phần sữa chua dâu cho đơn hàng đầu tiên trong tháng.";

$(document).ready(function(){
  $("footer").append( "<div id='adscontainer'><span id='adstext'><h2>"+ads+"</h2></span></div>"); 
  var wm=($(window).width()-$("main").width())/2;
  if(wm>=200) {	
	adsVerEffect();
  }
  else {	
    adsHorEffect();
  }
  headlineEffect(); 
});

function adsVerEffect() {
  $("#adscontainer").addClass("adsvercontainer container");
  $("#adscontainer").css("width", ($(window).width() - $("main").width())/2);  
  $("#adstext").addClass("adsvertext adstext");	
  $('#adstext').css('top', $('#adscontainer').height());
  $('#adstext').animate(
    {top: '-='+($('#adscontainer').height()+$('#adstext').height())},
    30000,
    function() {
	  adsVerEffect();
    }
  );
}

function adsHorEffect() {
  $("#adscontainer").addClass("adshorcontainer container");
  $("#adscontainer").css("left", $("main").position().left);
  $("#adscontainer").css("width", $("main").width());
  $("#adstext").addClass("adshortext adstext"); 	
  $('#adstext').css('left', $('#adscontainer').width());	
  $('#adstext').animate(
    {left: '-='+($('#adscontainer').width()+$('#adstext').width())},
    30000,
    function() {
	  adsHorEffect();
    }
  );
}

var headlineContent = [
  {
    "title":"Bánh flan sữa chua - sự kết hợp hoàn hảo",
    "photo":"images/trangchu/headline/headline1.jpg"
  },
  {
    "title":"Sữa chua làm từ sữa dê - đậm đà hương vị khó quên",
    "photo":"images/trangchu/headline/headline2.jpg"
  },
  {
    "title":"Thưởng thức sữa chua theo cách của bạn",
    "photo":"images/trangchu/headline/headline3.jpg"
  }
];

function init() {
  for (let i=0; i < headlineContent.length; i++){
    var item = headlineContent[i];
	var dc = $("<div>");
	$("<span><h3>"+item.title+"</h3></span>").appendTo(dc);
	$("<img src='"+item.photo+"'/>").appendTo(dc);
	$("#headline").append(dc);
  }
}

function headlineEffect(){
  init();
  $("#headline > div:gt(0)").hide();
  setInterval(function() { 
	$('#headline > div:first')
	  .hide()
	  .next()
	  .fadeIn(1000)
	  .end()
	  .appendTo('#headline');
  }, 5000);	
}
