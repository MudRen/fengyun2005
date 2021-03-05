// searoad.c
inherit ROOM;
void create()
{
        set("short", "海边路");
        set("long", @LONG
路面上的沙石越来越细，空气中弥漫着一股咸味，越往前走，咸味越明显。远
处隐隐传来波涛拍岸的声音。偶尔走过去一两个满脸水纹的老渔夫，肩上扛着渔具，
爽朗地大声谈笑。
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"searoad",
  		  "south" : __DIR__"seaside",
  		  "north":  __DIR__"seaside1",
		]));         
	set("objects",([
        	AREA_TIEFLAG"npc/fishman" : 1,
       	]) );
        set("outdoors", "tieflag");
	set("coor/x",1000);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
