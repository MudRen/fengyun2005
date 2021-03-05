

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "笑浅楼底层");
  set ("long", @LONG

　　　　玉盘银冷桂花路，残香红暖宿星街
　　　　指抱离壶秋深浅，月落愁杯看盈缺
　　　　洁然洁然无酒色，味比前年后院雪
　　　　雪润愁肠魂先醒，寒影寒心寒时觉

　　　　人持芳枝勤相邀，笑跃唇齿语不歇
　　　　微眼沉眉忙推就，颊染胭脂鬓乌夜
　　　　醉非好醉应独醉，夜在重阳不堪歇
　　　　莫怪月满不留君，留君最属君庭月

LONG);
        set("exits", ([
"117" : __DIR__"userroom/youa1567054576",
"116" : __DIR__"userroom/nerd1566785571",
"115" : __DIR__"userroom/zen1512957889",
"114" : __DIR__"userroom/noyes1512812441",
"113" : __DIR__"userroom/fire1512709616",
"110" : __DIR__"userroom/poemecho1508152945",
"109" : __DIR__"userroom/starsoul1508152608",
"108" : __DIR__"userroom/yyg1508028392",
"107" : __DIR__"userroom/xbb1507916754",
"106" : __DIR__"userroom/cut1507764619",
"105" : __DIR__"userroom/sceneb1507215966",
"104" : __DIR__"userroom/scenea1507215540",
"103" : __DIR__"userroom/xiao1506663580",
"102" : __DIR__"userroom/xiaoqing1506102030",
"101" : __DIR__"userroom/gxk1505351808",
		  "up" : __DIR__"smile"+(query("floor")+1), 
  			"south" : __DIR__"enterance", 
]));
  	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",query("floor")*40);
	setup();
}
