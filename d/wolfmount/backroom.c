inherit ROOM;

void create()
{
	set("short", "后厅");

	set("long", @LONG
珠帘后是个小厅，一个红木高台上摆着张虎皮椅，一个神色木然的老人正呆坐
其上一动不动，空气种弥漫着一种诡异而浓烈的檀香味。
LONG);
	set("type","indoors");
	set("exits",([
		"north":__DIR__"shuaiyi",
	]) );
    set("indoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/zhuwu":1,
     		__DIR__"npc/kunlun1":1,
     		__DIR__"npc/kunlun2":1,
    	]) );
	set("coor/x",40);
	set("coor/y",-110);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}
