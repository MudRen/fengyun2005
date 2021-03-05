inherit EQUIP;
void create()
{
        set_name("乌衣", ({ "dark cloth","cloth" }) );
        set_weight(600);
        set("long","一件乌黑的麻衣。\n");
                set("unit", "件");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "mask");
				set("fakegender", "男性");
                set("armor_prop/id", ({"master tianfeng"}) );
                set("armor_prop/name", ({"天枫十四郎"}) );
				set("armor_prop/short", ({"天枫十四郎(Master tianfeng)"}) );
                set("armor_prop/long", ({"一个面色蜡黄，浓眉高颧的乌衣老者，浑身尽是杀气。他盘膝坐在山巅之上，
衣抉下露出赤足，却将一双高齿乌木的木屐端放于前，木屐上竟又放着柄乌
鞘长刀。"}) );

                set("tianfeng_skinmask",1);
}
