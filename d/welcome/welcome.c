inherit ROOM;
void create()

{
	set("short", "欢迎光临风云世界");
	set("long", @LONG
一道白光闪过，你发现自己忽然来到了一个陌生的地方，这儿很高，似在云间，
向下看是熙熙攘攘车水马龙的街道，莫非那就是传说中的风云城？左面竖着一块木
牌，也许你应该看一看（ｌｏｏｋ　ｓｉｇｎ）。
LONG
	);
	set("exits", ([
  		"down" :  __DIR__"newbie1",
	]));
	set("item_desc", ([
		"sign": "
你想看看你在哪里(l, look),你想知道这个世界里都有谁(who),
或许你要四处走走，(w,s,n,e,nw,ne,,sw,se,d,u,sd,nd,wd,ed,wu,nu,eu,su)，
不过你得先看看有那些出口。
新手请用new加空格，然后再加上要说的话来聊天。\n"
	]));
	
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",1000);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}
