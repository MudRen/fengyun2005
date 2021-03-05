
inherit ROOM;

void create()
{
        set("short", "太清殿");
        set("long", @LONG
太清殿原来是三清观中收藏书籍的地方，丁氏兄妹来后这里就成了丁白云修身
养性的居所。白云观主深居简出，这儿除了她的亲传弟子谁都不准进入。四周的书
架上堆了满满的书，有些已经旧的纸张都泛黄了，角落里一座小小的木梯通往二楼。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"up" : __DIR__"book_room2",
  		"south" : __DIR__"stoneroad2",
	]));
        set("objects", ([
		__DIR__"npc/jing2" : 1,
 	]) );
 	
        set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}


int valid_leave(object who, string dir) {
	object guard;
	guard = present("qingyi",this_object());

	if (dir == "up" && guard && !REWARD_D->check_m_success(who,"三清锄奸")) {
		if (who->query("gender") != "女性")
			return notify_fail(guard->name()+"说：“白云观主不见生客，施主请止步。”\n");
	}
	return 1;
}

	