

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "藏剑阁底层");
  set ("long", @LONG

　　　　少年听雨歌楼上，红烛昏罗帐。
　　　　壮年听雨客舟中，江阔云低，断雁叫西风。
　　　　而今听雨僧庐下，鬓已星星也。
　　　　悲欢离合总无情，一任阶前点滴到天明。

LONG);
        set("exits", ([
"117" : __DIR__"userroom/xiaox1575377403",
"112" : __DIR__"userroom/langtl1561118894",
"114" : __DIR__"userroom/hulusl1554789944",
"113" : __DIR__"userroom/hulumyc1554787481",
"111" : __DIR__"userroom/mate1514475345",
"110" : __DIR__"userroom/redis1513004387",
"109" : __DIR__"userroom/joe1512782630",
"108" : __DIR__"userroom/suki1512782020",
"107" : __DIR__"userroom/harder1508219744",
"106" : __DIR__"userroom/dummya1508219327",
"105" : __DIR__"userroom/gandalf1507528984",
"104" : __DIR__"userroom/slat1506870957",
"103" : __DIR__"userroom/slbt1506864846",
"102" : __DIR__"userroom/shifx1506424313",
"101" : __DIR__"userroom/keen1504700177",
//  "down" : __DIR__"sword"+(query("floor")-1),
  "up" : __DIR__"sword"+(query("floor")+1), 
  "east" : __DIR__"enterance", 
]));
  	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
