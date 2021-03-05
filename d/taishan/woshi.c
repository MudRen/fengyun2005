// Room: woshi.c --- by MapMaker

inherit ROOM;

void create()
{
    set("short", "合璧小筑");

	set("long", @LONG
如果只用一个字来描述这间卧室的话,那就是"静"了。房中除了张大床外,别无
他物.缎被锦帐收拾的异常整齐肃静.几丝阳光透过竹帘,显得格外安谧.
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
	"east":__DIR__"dating",
	]) );
	//}}
        set("indoors", "taishan");
	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",150);

	setup();
	replace_program(ROOM);
}
