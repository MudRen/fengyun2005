inherit ROOM;
void create()
{
  set("short","阳关大道");
  set("long",@LONG
这是一条东西大道，笔直宽阔，道旁是绿油油的麦田，向南可以隐约看到风云
城的城门，向北是从前的[33m『泰安花园』[32m，曾是游历风云的侠女志士们建家兴宅的所
在，可惜如今已被朝廷殷大人以违章搭盖为由拆成一片废墟。东边通向泉城济南，
已是山东地界。
LONG
  );
  	set("exits",([
         "west" :AREA_LAOWU"road2",
         "east" :__DIR__"shanjiao",
               ]));

        set("outdoors", "jinan");
	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}

