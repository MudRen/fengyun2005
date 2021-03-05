inherit ROOM;

void create()
{
	set("short", "燕子坞");

	set("long", @LONG
这里是燕七的卧室。平常燕七倒算是豪爽，但一回到这里，便古古怪怪的，大
门紧闭，连窗户都会关上，郭大路好几次想进来，都被燕七轰了出去，弄得郭大路
好生没趣，一怒之下，趁燕七出门，在屋里还算雪白的墙上留下了郭大少的弥足珍
贵的题词“燕子坞”。屋子里其实除了张床外，什么也没有。郭大路费尽心思，也
没发现有什么不可告人的地方。
LONG);

	set("type","indoors");
	set("exits",([
		"west":__DIR__"grass4",
		"south":__DIR__"grass3",
	]) );
        set("objects", ([
    __DIR__"obj/bed2" : 1,
       	]) );
        set("item_desc", ([
                "墙": "墙上面龙飞凤舞写了几个大字：\n郭大路到燕子坞一游，哈哈！可惜啥好玩的没有。\n",
                "wall": "墙上面龙飞凤舞写了几个大字：\n郭大路到燕子坞一游，哈哈！可惜啥好玩的没有。\n",
        ]) );

	set("coor/x",20);
	set("coor/y",240);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
