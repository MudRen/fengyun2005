// wizard_j.c

inherit BULLETIN_BOARD;
void create()
{
	set_name("意见交流板", ({ "idea board", "board" }) );
	set("location", AREA_WIZ"jobroom");
	set("board_id", "wizard_j");
	set("long",	"这是一个专门为玩家和管理人员沟通的意见板。\n" );
	setup();
        set("capacity", 49);
        replace_program(BULLETIN_BOARD);
}
