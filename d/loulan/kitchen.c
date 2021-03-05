inherit ROOM;

void create()
{
        set("short", "御膳房");
        set("long", @LONG
快活王酒量极豪，喜欢以大曲，茅台，高粱，及竹叶青掺合之烈酒，配以烤至
半熟之蜗牛，牡蝈，或蛇肉佐食，不喜猪肉，从不进口，偶尔意兴所至，也吩咐膳
房里的厨子们弄些松江的鲈鱼，洋澄湖的活蟹，定海的对虾，江南的脆鳝等等，养
在门口的一口大水缸里。而这些厨子都是天南地北的一流大厨，快活王笑言此处才
是天下唯一真正的御膳房。
LONG
        );

        set("exits", ([ 
		"west" : __DIR__"northstrt",
	]));
        set("resource/water", 1);
	set("liquid/container", "水缸");  
        set("objects", ([
               __DIR__"npc/cooker" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
