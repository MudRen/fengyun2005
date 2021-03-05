// common_b.c

inherit BULLETIN_BOARD;

void create()
{
    set_name("风云屏风", ({ "board" }) );
	set("location", AREA_FY"fyge");
	set("board_id", "common_fy");
	set("long",	"这是风云阁门前的屏风，上面有着很多纸条。\n" );
	setup();
	set("capacity", 99);
	replace_program(BULLETIN_BOARD);
}
