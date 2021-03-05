#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( HIR "刀枪不入" NOR, ({ "jade" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长的精铁禅杖，上面镶著一个环。\n");
                set("no_drop",1);
                set("timestamp","amtpoaf");
                set("no_get",1);
                set("owner","ssa");
                set("rigidity",400);
		set("material", "iron");
		set("wield_msg", "$N拿出一根乌黑的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_staff(30);
}

string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+"."+query("timestamp"));
}
int save()
{
        string file;
        string equipped;
        int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                equipped = (string)query("equipped");
                delete("equipped");
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                set("equipped",equipped);
                return result;
        }
        return 0;
}
int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
        {
                set_weight(query("weight"));
                return 1;
        }
        return 0;
}

