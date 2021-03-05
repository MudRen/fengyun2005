inherit ROOM;

void create()
{
        set("short", "争春苑");
        set("long", @LONG
这是间华丽而宽敞的庭院，华丽得不似人间所有，在暗淡而销魂的灯光下，有
二三十个身穿轻纱的少女，长发披散，赤着雪白的天足。轻纱朦胧，并没有遮住她
们可爱的躯体，反而将她们的胴体衬托得更可爱，更神秘，更令人心动。有的斜倚
在虎皮褥旁，轻挑慢然，弄着管弦，有的手托香腮，慢声低唱，也有的随着歌声，
婀娜起舞，轻纱飘扬，春光掩映，那雪玉般的肌肤，虽只让人匆匆一瞥，但却也更
令人心施摇荡，不能自主。
LONG
        );

	set("exits", ([ 
		"north" : __DIR__"weststrt2",
	]));
        set("indoors", "loulan");
        set("objects", ([
		__DIR__"npc/beauty1" : 2,
		__DIR__"npc/beauty2" : 2,
	]) );

	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}