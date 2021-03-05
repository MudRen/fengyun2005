
inherit ROOM;

void create()
{
        set("short", "集市口");
        set("long", @LONG
这里是中原入西域的必经之路，大批的商人骆驼队都一定要从这里经过，时间
长了，就成了个有点热闹的集市，集市上卖的都是些过沙漠的必备物品，骆驼，水
袋、粮食、宿具，以及一些零零碎碎，看来虽无用，到时都有用的东西。
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"saikou",
 		"south": __DIR__"fair2",
	]));
        set("outdoors", "quicksand");
        set("objects", ([
                
        ]) );

	set("coor/x",-1030);
	set("coor/y",-5);
	set("coor/z",0);
	setup();

}

