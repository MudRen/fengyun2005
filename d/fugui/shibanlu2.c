inherit ROOM;

void create()
{
	set("short", "碎石小路");

	set("long", @LONG
这条碎石小路东边是一个梨园，西首便是富贵如意厅，路上生满了青苔，一不
当心就会跌倒，两侧不知名的野花开得倒也茂盛，淡淡的散发着一种清新的花香。
草窠中偶尔传来一两声蟋蟀的叫声。一抬头，可以看见几个或是蜈蚣状，或是老鹰
状的风筝高高飞舞在蓝天白云中。
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"east":__DIR__"liyuan",
		"west":__DIR__"fuguitin",
	]) );
        set("objects" , ([
	    __DIR__"obj/flower" : 1,
        ]));
	set("coor/x",20);
	set("coor/y",210);
	set("coor/z",80);
        setup();
}
/*
int valid_leave(object me, string dir)
{
    if (!wizardp(this_player()) && (dir=="west" || dir=="east"))
         {
           if( random((int)this_player()->query("kar")) < 2 )
              {
               message_vision("$N一脚踩在青苔上, 不小心滑了一跤, 四脚朝天地摔在地上起不来。\n\n\n", this_player());
               this_player()->unconcious();
              return 0;
              }
           else return 1;
         }
     else return 1;
}
 */ 