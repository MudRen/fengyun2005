inherit __DIR__"no_killing_place";
void create()
{
	set("short", "村居");
	set("long", @LONG
眼前是几处极为普通的村舍，几个小孩子正在屋外追逐打闹，几只肥肥的大白
鹅，看见你来，伸长了脖子嘎嘎的叫，似乎奇怪你居然找到了这里。这里每当夕阳
西下的时候，厚厚的茅草毡成的屋顶便会被淡淡的炊烟罩住，整个村里弥漫着一股
诱人的米饭的香味。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
   		"south" : __DIR__"nongjia",
   		"west" : __DIR__"guojia",
   		"north" : __DIR__"farm",
   	]));

	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program( __DIR__"no_killing_place");
}


