
inherit ROOM;

void create()
{
        set("short", "塞口");
        set("long", @LONG
这里是中原入西域的必经之路，向西可以看到一段破旧的长城，上面好象还有
被土炮轰过的痕迹。大批的商人骆驼队从这里经过，形成了一个小小的[33m集市[32m。不知
为什么，最近这里却繁华起来，行商都爱停下来歇歇脚，还搬来了几户人家。
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"sandroad",
  		"west" : __DIR__"oldgreatwall",
 		"south": __DIR__"fair",

]));
        set("outdoors", "quicksand");
        set("objects", ([
                
        ]) );

	set("coor/x",-1030);
	set("coor/y",0);
	set("coor/z",0);
	setup();

}

