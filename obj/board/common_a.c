// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("一般用途留言板", ({ "board" }) );
	set("location", AREA_GUANWAI"inn");
	set("board_id", "common_a");
	set("long",	"这是一个供人留言记事的留言板。\n" );
	setup();
	set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}
