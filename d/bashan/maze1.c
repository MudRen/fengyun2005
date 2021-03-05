// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit VRM_SERVER;

void create()
{
    set_inherit_room(__DIR__"maze1-room");

    set_maze_long(6,6);
    set_maze_spacing(1);
    set_maze_refresh(0);

    set_entry_dir("east");

    set_link_entry_dir("east");
    set_link_entry_room(__DIR__"enterance");
    set_link_entry_room_x(0);
    set_link_entry_room_y(0);
    set_link_entry_room_z(0);

    set_link_exit_dir("west");
    set_link_exit_room(__DIR__"jadegate");


    set_entry_short(MAG"古佛窟入口"NOR);
    set_entry_desc(@LONG
再往里去，就是小巴山传闻中神秘莫测的古佛窟。站在洞口看去，只见灰岩风
锈，貌不惊人，但据曾侥幸自佛窟中逃出性命的人说，窟内借万尊佛像之力布有奇
门阵法，能以五音五色乱人心脉，一进佛窟，就只见各种幻象层出不穷，定力稍有
不坚，便会迷失在异象之中。
LONG
    );

    set_exit_short(MAG"古佛窟后"NOR);
    set_exit_desc(@LONG
走出这座让人神智迷乱的古佛窟，你不禁深深的吁出一口长气。回想起窟中种
种幻象，冷汗瞬间便浸湿了你的衣衫。佛窟后是一条窄小的通路，通路并不甚长，
站在这里已可以看见尽处的一扇青色石门。
LONG
    );

    set_maze_room_short(MAG"古佛窟"NOR);
    set_maze_room_desc(@LONG
再往里去，就是小巴山传闻中神秘莫测的古佛窟。站在洞口看去，只见灰岩风
锈，貌不惊人，但据曾侥幸自佛窟中逃出性命的人说，窟内借万尊佛像之力布有奇
门阵法，能以五音五色乱人心脉，一进佛窟，就只见各种幻象层出不穷，定力稍有
不坚，便会迷失在异象之中。
LONG
    );

}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
