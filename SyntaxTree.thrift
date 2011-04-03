
namespace java tw.maple.generated
namespace cpp tw.maple.generated

typedef list<string> StringList

enum ExpressionType
{
    IDENTIFIER,
    CALL
}

enum IdentifierType
{
    TYPE_IDENTIFIER,
    ATTR_IDENTIFIER,
    IDENTIFIER, 
}

struct Identifier
{
    1: IdentifierType type,
    2: string name,
}

struct CallExpression
{
    1: bool is_new = 0,
}

service AstDumper
{
    oneway void startProgram( ),
    oneway void endProgram( ),

    oneway void startPackage( 1: StringList id ),
    oneway void endPackage( 1: StringList IDs ),

    oneway void startExpressionList( ),
        oneway void startCallExpression( 1: CallExpression call ),
            oneway void startAgumentList(),
            oneway void endAgumentList(),
        oneway void endCallExpression(),
        oneway void identifierExpression( 1: Identifier id ),
    oneway void endExpressionList( ),

    oneway void addImport( 1: StringList packages ),   // Do we need this? using namespace? or what ever suck?

    oneway void startStmtList(),
//       oneway void defineVariables( 1: list<Variable> vars ),
//       oneway void defineExpression( 1: list<Expression> exprs ),
    oneway void endStmtList(),

    oneway void ping(),
    oneway void ping2( 1: i32 echo ),
}

