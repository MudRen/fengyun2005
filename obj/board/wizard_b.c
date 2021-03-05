// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("管理事项板", ({ "board" }) );
	set("location", AREA_WIZ"hall");
	set("board_id", "wizard_b");
	set("long",
		"这是一个供管理人员们相互留言的板。\n" );
	setup();
	set("capacity", 88);
	replace_program(BULLETIN_BOARD);
}
