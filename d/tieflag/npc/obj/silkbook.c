// book.c
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name( "锦册", ({ "silk book", "book" }));
    set_weight(100);
    set("unit", "本");
    set("long", "这是铁中棠之父铁毅用鲜血写成的一本小册子。（read）\n");
    set("value", 1);
    set("skill", ([
        "name":                 "jiayiforce",
        "exp_required": 5000,                
        "sen_cost":             40,     
        "difficulty":   30,            
        "max_skill":    70           
    ]) );
    ::init_item();
} 

void init()
{
        add_action("do_read", "read");
} 

int do_read()
{
	object me;
	me=this_player();
	message_vision(YEL "\n $n翻开锦册的第一页。\n" NOR, this_object(), me);
	write(RED"    昔年三怪、四煞、七魔、九恶、十八寇为害江湖，惨无人道，江湖中人\n"NOR);
	write(RED"敢怒不敢言，隐藏多年。\n"NOR);
	write(RED"    直至本门云、铁两位先人出道江湖，黄山、洞庭、点苍、太湖、祁连、\n"NOR);
	write(RED"昆仑、中条七役，大小数十战，终以两柄神剑，杀尽三怪、四煞、七魔、\n"NOR);
	write(RED"九恶、十八寇，以此四十一人之鲜血，染成一面大旗。\n"NOR);
	write(RED"江湖人感恩图报，大旗所至，群相伏首。\n"NOR);
	write(RED"    是以云、铁两祖创立我大旗门，以德义立门，以德义立规，以德义服人。\n"NOR);
	write(RED"   “愿吾后代门人，勿忘忠、孝、仁、爱、信、义、和、平八字，谨守门\n"NOR);
	write(RED"规，扶弱锄强，发扬正义。”\n"NOR);
	write(RED"    旁边一行字迹，写的是：“大旗门第二代云老先人遗墨，铁毅恭录。”\n"NOR);
	write("\n");
	me->set_temp("mark/silkbook",1);
	return 1;
}
