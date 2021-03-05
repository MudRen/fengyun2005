//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "鹦鹉阁分号");
    set("long", @LONG
这里是风云城鹦鹉阁的分号，一间小巧精致的店铺，招牌上写着“鹦鹉阁”三
字，没有什么奇珍异宝，只有两个大大的红木书橱，挂着黄铜大锁。阁里卖的是一
些稀奇古怪的东西，据说都是主人当年游历四方所觅得。鹦鹉阁的老板娘似乎不是
中土人氏，整天躺在椅子上懒懒地看书。
LONG
    );
    set("exits",
      ([
		"north": __DIR__"skystreet4",
      ]));
    set("objects",
      ([
			__DIR__"npc/shaman" : 1,
      ]));
    set("coor/x",20);
    set("coor/y",-170);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
