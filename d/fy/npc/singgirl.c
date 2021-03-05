inherit NPC;
#include <ansi.h>
void create()
{
        set_name("徐宁", ({ "xu ning","sing girl","silencer" }) );
        set("gender", "男性" );
        set("age", 31);
        set("title", CYN"梨园七杰之"NOR);
        set("nickname", WHT"花落东君染蝶衣"NOR);
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

void do_ggyy(int count)
{
        object me;
        string msg;
		object room;
        string *event_msg = ({
CYN"只见得红幕拉起，台上转出几儿郎。\n"NOR,
CYN"那一厢，一身淡色长裙的白素贞漫声清唱：\n"NOR,

WHT"\n离却了峨嵋到江南，\n"NOR,
WHT"人世间竟有这美丽的湖山!\n"NOR,
WHT"这一旁亭台倒映在波光里面，\n"NOR,
WHT"那一旁好楼台紧傍着三潭；\n"NOR,
WHT"苏堤上杨柳丝把船儿轻挽，\n"NOR,
WHT"颤风中桃李花似怯春寒。\n"NOR,

CYN"\n白素贞顿了一顿，清清嗓子接着唱道：\n"NOR,
WHT"虽然是叫断桥桥何曾断，\n"NOR,
WHT"桥亭上过游人两两三三。\n"NOR,
WHT"对这等好湖山愁眉尽展，\n"NOR,
WHT"也不枉下峨嵋走这一番。\n"NOR,

WHT"\n一刹时天色变风狂云暗，\n"NOR,
WHT"好一似洛阳道巧遇潘安。\n"NOR,
WHT"这颗心千百载微游不泛，\n"NOR,
WHT"却为何今日里陡起波澜?\n"NOR,

CYN"\n那厢里转出一个白衣公子，手中持着绿竹伞。\n"NOR,
CYN"美公子执伞前相探，雨声里雏音发清唱：\n"NOR,
MAG"适才扫墓灵隐去，\n"NOR,
MAG"归来风雨忽迷离。\n"NOR,
MAG"百忙中那有闲情意，\n"NOR,
MAG"柳下避雨怎相宜?\n"NOR,

WHT"\n雨过天晴湖山如洗，春风习习透裳衣。\n"NOR,
MAG"\n真乃是西湖比西子，淡妆浓抹总相宜。\n"NOR,
WHT"\n问郎君家在何方住？改日登门叩谢伊。 \n"NOR,

MAG"\n寒家住在清波门外，钱王词畔小桥西。\n"NOR,
MAG"些小之事何足介意，怎敢劳玉趾访寒微？\n"NOR,

WHT"\n这君子老成令人喜，有答无问把头低。\n"NOR,
WHT"青儿再去说仔细，请郎君得暇访曹词。\n"NOR,

WHT"\n多谢君子思义广，殷勤送我到钱塘。\n"NOR,
WHT"我家住在红楼上，还望君子早降光。\n"NOR,
WHT"青儿扶我把湖岸上，\n"NOR,
WHT"莫教我望穿秋水想断柔肠。\n"NOR,

CYN"\n白素贞扶着小青的手，缓缓转到台后。\n"NOR,
CYN"许仙看着白素贞消失的方向出神，片刻又唱：\n"NOR,

MAG"\n一见神仙归天上、不问姓名成荒唐。\n"NOR,
MAG"好一个小娘子伶俐无双，驾鸳端合有红娘。\n"NOR,

CYN"\n红幕缓缓落下，了结去这一宗《西湖借伞》。\n"NOR,
});
        me = this_object();
        msg = event_msg[count];
//        message_vision(msg,me);
		room = find_object("/d/fy/theater");
		if (!room)
			room = load_object("/d/fy/theater");
		tell_room(room,msg);
        if (count < sizeof(event_msg)-1)
                call_out("do_ggyy",1+random(2),count+1);
        return;

}



