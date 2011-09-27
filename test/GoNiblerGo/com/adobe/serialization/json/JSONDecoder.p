
program 
  statementlist 
    config namespace  
      identifier CONFIG 
    import  
      packagename 
        packageidentifiers 
          identifier __AS3__
          identifier vec
          identifier Vector
    package 
      packagename 
        packageidentifiers 
          identifier com
          identifier adobe
          identifier serialization
          identifier json
    import  
      packagename 
        packageidentifiers 
          identifier __AS3__
          identifier vec
          identifier Vector
    class 
      attributelist 
        list 
          member 
            get lexical 
              identifier public
      qualifiedidentifier JSONDecoder 
        qualifier 
          attributelist 
            list 
              member 
                get lexical 
                  identifier public
      statementlist 
        var 
          attributelist 
            list 
              member 
                get lexical 
                  identifier private 
          list 
            variablebinding 
              typedidentifier 
                qualifiedidentifier strict 
                  qualifier 
                    attributelist 
                      list 
                        member 
                          get lexical 
                            identifier private
                typeexpr 
                  member 
                    get lexical 
                      identifier Boolean
        var 
          attributelist 
            list 
              member 
                get lexical 
                  identifier private 
          list 
            variablebinding 
              typedidentifier 
                qualifiedidentifier value 
                  qualifier 
                    attributelist 
                      list 
                        member 
                          get lexical 
                            identifier private
        var 
          attributelist 
            list 
              member 
                get lexical 
                  identifier private 
          list 
            variablebinding 
              typedidentifier 
                qualifiedidentifier tokenizer 
                  qualifier 
                    attributelist 
                      list 
                        member 
                          get lexical 
                            identifier private
                typeexpr 
                  member 
                    get lexical 
                      identifier JSONTokenizer
        var 
          attributelist 
            list 
              member 
                get lexical 
                  identifier private 
          list 
            variablebinding 
              typedidentifier 
                qualifiedidentifier token 
                  qualifier 
                    attributelist 
                      list 
                        member 
                          get lexical 
                            identifier private
                typeexpr 
                  member 
                    get lexical 
                      identifier JSONToken
        function 
          attributelist 
            list 
              member 
                get lexical 
                  identifier public
          functionname 
            qualifiedidentifier JSONDecoder 
              qualifier 
                attributelist 
                  list 
                    member 
                      get lexical 
                        identifier public
          functioncommon 
            functionsignature 
              parameterlist 
                parameter 
                  identifier s
                  typeexpr 
                    member 
                      get lexical 
                        identifier String
                parameter 
                  identifier strict
                  typeexpr 
                    member 
                      get lexical 
                        identifier Boolean
            statementlist 
              expression 
                list 
                  member 
                    this
                    set dot 
                      identifier strict
                      argumentlist 
                        member 
                          get lexical 
                            identifier strict
              expression 
                list 
                  member 
                    set lexical 
                      identifier tokenizer
                      argumentlist 
                        member 
                          construct lexical 
                            identifier JSONTokenizer
                            argumentlist 
                              member 
                                get lexical 
                                  identifier s
                              member 
                                get lexical 
                                  identifier strict
              expression 
                list 
                  member 
                    call lexical 
                      identifier nextToken
              expression 
                list 
                  member 
                    set lexical 
                      identifier value
                      argumentlist 
                        member 
                          call lexical 
                            identifier parseValue
              if 
                list 
                  binary logicaland 
                    member 
                      get lexical 
                        identifier strict
                    binary notequals 
                      member 
                        call lexical 
                          identifier nextToken
                      literalnull 
                statementlist 
                  expression 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier tokenizer
                        call dot 
                          identifier parseError
                          argumentlist 
                            literalstring:Unexpected characters left in input stream 
              return 
        function 
          attributelist 
            list 
              member 
                get lexical 
                  identifier public
          functionname 
            qualifiedidentifier getValue 
              qualifier 
                attributelist 
                  list 
                    member 
                      get lexical 
                        identifier public
          functioncommon 
            functionsignature 
            statementlist 
              return 
                list 
                  member 
                    get lexical 
                      identifier value
              return 
        function 
          attributelist 
            member 
              get lexical 
                identifier final
            list 
              member 
                get lexical 
                  identifier private
          functionname 
            qualifiedidentifier nextToken 
              qualifier 
                attributelist 
                  member 
                    get lexical 
                      identifier final
                  list 
                    member 
                      get lexical 
                        identifier private
          functioncommon 
            functionsignature 
              typeexpr 
                member 
                  get lexical 
                    identifier JSONToken
            statementlist 
              return 
                list 
                  member 
                    set lexical 
                      identifier token
                      argumentlist 
                        member 
                          member 
                            get lexical 
                              identifier tokenizer
                          call dot 
                            identifier getNextToken
              return 
        function 
          attributelist 
            member 
              get lexical 
                identifier final
            list 
              member 
                get lexical 
                  identifier private
          functionname 
            qualifiedidentifier nextValidToken 
              qualifier 
                attributelist 
                  member 
                    get lexical 
                      identifier final
                  list 
                    member 
                      get lexical 
                        identifier private
          functioncommon 
            functionsignature 
              typeexpr 
                member 
                  get lexical 
                    identifier JSONToken
            statementlist 
              expression 
                list 
                  member 
                    set lexical 
                      identifier token
                      argumentlist 
                        member 
                          member 
                            get lexical 
                              identifier tokenizer
                          call dot 
                            identifier getNextToken
              expression 
                list 
                  member 
                    call lexical 
                      identifier checkValidToken
              return 
                list 
                  member 
                    get lexical 
                      identifier token
              return 
        function 
          attributelist 
            member 
              get lexical 
                identifier final
            list 
              member 
                get lexical 
                  identifier private
          functionname 
            qualifiedidentifier checkValidToken 
              qualifier 
                attributelist 
                  member 
                    get lexical 
                      identifier final
                  list 
                    member 
                      get lexical 
                        identifier private
          functioncommon 
            functionsignature 
            statementlist 
              if 
                list 
                  binary equals 
                    member 
                      get lexical 
                        identifier token
                    literalnull 
                statementlist 
                  expression 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier tokenizer
                        call dot 
                          identifier parseError
                          argumentlist 
                            literalstring:Unexpected end of input 
              return 
        function 
          attributelist 
            member 
              get lexical 
                identifier final
            list 
              member 
                get lexical 
                  identifier private
          functionname 
            qualifiedidentifier parseArray 
              qualifier 
                attributelist 
                  member 
                    get lexical 
                      identifier final
                  list 
                    member 
                      get lexical 
                        identifier private
          functioncommon 
            functionsignature 
              typeexpr 
                member 
                  get lexical 
                    identifier Array
            statementlist 
              var  
                list 
                  variablebinding 
                    typedidentifier 
                      qualifiedidentifier a
                      typeexpr 
                        member 
                          get lexical 
                            identifier Array
                    member 
                      construct lexical 
                        identifier Array
              expression 
                list 
                  member 
                    call lexical 
                      identifier nextValidToken
              if 
                list 
                  binary equals 
                    member 
                      member 
                        get lexical 
                          identifier token
                      get dot 
                        identifier type
                    member 
                      member 
                        get lexical 
                          identifier JSONTokenType
                      get dot 
                        identifier RIGHT_BRACKET 
                statementlist 
                  return 
                    list 
                      member 
                        get lexical 
                          identifier a 
                statementlist 
                  if 
                    list 
                      binary logicaland 
                        unary not 
                          member 
                            get lexical 
                              identifier strict
                        binary equals 
                          member 
                            member 
                              get lexical 
                                identifier token
                            get dot 
                              identifier type
                          member 
                            member 
                              get lexical 
                                identifier JSONTokenType
                            get dot 
                              identifier COMMA 
                    statementlist 
                      expression 
                        list 
                          member 
                            call lexical 
                              identifier nextValidToken
                      if 
                        list 
                          binary equals 
                            member 
                              member 
                                get lexical 
                                  identifier token
                              get dot 
                                identifier type
                            member 
                              member 
                                get lexical 
                                  identifier JSONTokenType
                              get dot 
                                identifier RIGHT_BRACKET 
                        statementlist 
                          return 
                            list 
                              member 
                                get lexical 
                                  identifier a 
                        statementlist 
                          expression 
                            list 
                              member 
                                member 
                                  get lexical 
                                    identifier tokenizer
                                call dot 
                                  identifier parseError
                                  argumentlist 
                                    binary plus 
                                      literalstring:Leading commas are not supported.  Expecting ']' but found 
                                      member 
                                        member 
                                          get lexical 
                                            identifier token
                                        get dot 
                                          identifier value 
              while 
                list 
                  literalboolean 1 
                statementlist 
                  expression 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier a
                        call dot 
                          identifier push
                          argumentlist 
                            member 
                              call lexical 
                                identifier parseValue
                  expression 
                    list 
                      member 
                        call lexical 
                          identifier nextValidToken
                  if 
                    list 
                      binary equals 
                        member 
                          member 
                            get lexical 
                              identifier token
                          get dot 
                            identifier type
                        member 
                          member 
                            get lexical 
                              identifier JSONTokenType
                          get dot 
                            identifier RIGHT_BRACKET 
                    statementlist 
                      return 
                        list 
                          member 
                            get lexical 
                              identifier a 
                    statementlist 
                      if 
                        list 
                          binary equals 
                            member 
                              member 
                                get lexical 
                                  identifier token
                              get dot 
                                identifier type
                            member 
                              member 
                                get lexical 
                                  identifier JSONTokenType
                              get dot 
                                identifier COMMA 
                        statementlist 
                          expression 
                            list 
                              member 
                                call lexical 
                                  identifier nextToken
                          if 
                            list 
                              unary not 
                                member 
                                  get lexical 
                                    identifier strict 
                            statementlist 
                              expression 
                                list 
                                  member 
                                    call lexical 
                                      identifier checkValidToken
                              if 
                                list 
                                  binary equals 
                                    member 
                                      member 
                                        get lexical 
                                          identifier token
                                      get dot 
                                        identifier type
                                    member 
                                      member 
                                        get lexical 
                                          identifier JSONTokenType
                                      get dot 
                                        identifier RIGHT_BRACKET 
                                statementlist 
                                  return 
                                    list 
                                      member 
                                        get lexical 
                                          identifier a   
                        statementlist 
                          expression 
                            list 
                              member 
                                member 
                                  get lexical 
                                    identifier tokenizer
                                call dot 
                                  identifier parseError
                                  argumentlist 
                                    binary plus 
                                      literalstring:Expecting ] or , but found 
                                      member 
                                        member 
                                          get lexical 
                                            identifier token
                                        get dot 
                                          identifier value
              return 
                list 
                  literalnull
              return 
        function 
          attributelist 
            member 
              get lexical 
                identifier final
            list 
              member 
                get lexical 
                  identifier private
          functionname 
            qualifiedidentifier parseObject 
              qualifier 
                attributelist 
                  member 
                    get lexical 
                      identifier final
                  list 
                    member 
                      get lexical 
                        identifier private
          functioncommon 
            functionsignature 
              typeexpr 
                member 
                  get lexical 
                    identifier Object
            statementlist 
              var  
                list 
                  variablebinding 
                    typedidentifier 
                      qualifiedidentifier o
                      typeexpr 
                        member 
                          get lexical 
                            identifier Object
                    member 
                      construct lexical 
                        identifier Object
              var  
                list 
                  variablebinding 
                    typedidentifier 
                      qualifiedidentifier key
                      typeexpr 
                        member 
                          get lexical 
                            identifier String
              expression 
                list 
                  member 
                    call lexical 
                      identifier nextValidToken
              if 
                list 
                  binary equals 
                    member 
                      member 
                        get lexical 
                          identifier token
                      get dot 
                        identifier type
                    member 
                      member 
                        get lexical 
                          identifier JSONTokenType
                      get dot 
                        identifier RIGHT_BRACE 
                statementlist 
                  return 
                    list 
                      member 
                        get lexical 
                          identifier o 
                statementlist 
                  if 
                    list 
                      binary logicaland 
                        unary not 
                          member 
                            get lexical 
                              identifier strict
                        binary equals 
                          member 
                            member 
                              get lexical 
                                identifier token
                            get dot 
                              identifier type
                          member 
                            member 
                              get lexical 
                                identifier JSONTokenType
                            get dot 
                              identifier COMMA 
                    statementlist 
                      expression 
                        list 
                          member 
                            call lexical 
                              identifier nextValidToken
                      if 
                        list 
                          binary equals 
                            member 
                              member 
                                get lexical 
                                  identifier token
                              get dot 
                                identifier type
                            member 
                              member 
                                get lexical 
                                  identifier JSONTokenType
                              get dot 
                                identifier RIGHT_BRACE 
                        statementlist 
                          return 
                            list 
                              member 
                                get lexical 
                                  identifier o 
                        statementlist 
                          expression 
                            list 
                              member 
                                member 
                                  get lexical 
                                    identifier tokenizer
                                call dot 
                                  identifier parseError
                                  argumentlist 
                                    binary plus 
                                      literalstring:Leading commas are not supported.  Expecting '}' but found 
                                      member 
                                        member 
                                          get lexical 
                                            identifier token
                                        get dot 
                                          identifier value 
              while 
                list 
                  literalboolean 1 
                statementlist 
                  if 
                    list 
                      binary equals 
                        member 
                          member 
                            get lexical 
                              identifier token
                          get dot 
                            identifier type
                        member 
                          member 
                            get lexical 
                              identifier JSONTokenType
                          get dot 
                            identifier STRING 
                    statementlist 
                      expression 
                        list 
                          member 
                            set lexical 
                              identifier key
                              argumentlist 
                                member 
                                  call lexical 
                                    identifier String
                                    argumentlist 
                                      member 
                                        member 
                                          get lexical 
                                            identifier token
                                        get dot 
                                          identifier value
                      expression 
                        list 
                          member 
                            call lexical 
                              identifier nextValidToken
                      if 
                        list 
                          binary equals 
                            member 
                              member 
                                get lexical 
                                  identifier token
                              get dot 
                                identifier type
                            member 
                              member 
                                get lexical 
                                  identifier JSONTokenType
                              get dot 
                                identifier COLON 
                        statementlist 
                          expression 
                            list 
                              member 
                                call lexical 
                                  identifier nextToken
                          expression 
                            list 
                              member 
                                member 
                                  get lexical 
                                    identifier o
                                set bracket 
                                  argumentlist 
                                    member 
                                      get lexical 
                                        identifier key
                                  argumentlist 
                                    member 
                                      call lexical 
                                        identifier parseValue
                          expression 
                            list 
                              member 
                                call lexical 
                                  identifier nextValidToken
                          if 
                            list 
                              binary equals 
                                member 
                                  member 
                                    get lexical 
                                      identifier token
                                  get dot 
                                    identifier type
                                member 
                                  member 
                                    get lexical 
                                      identifier JSONTokenType
                                  get dot 
                                    identifier RIGHT_BRACE 
                            statementlist 
                              return 
                                list 
                                  member 
                                    get lexical 
                                      identifier o 
                            statementlist 
                              if 
                                list 
                                  binary equals 
                                    member 
                                      member 
                                        get lexical 
                                          identifier token
                                      get dot 
                                        identifier type
                                    member 
                                      member 
                                        get lexical 
                                          identifier JSONTokenType
                                      get dot 
                                        identifier COMMA 
                                statementlist 
                                  expression 
                                    list 
                                      member 
                                        call lexical 
                                          identifier nextToken
                                  if 
                                    list 
                                      unary not 
                                        member 
                                          get lexical 
                                            identifier strict 
                                    statementlist 
                                      expression 
                                        list 
                                          member 
                                            call lexical 
                                              identifier checkValidToken
                                      if 
                                        list 
                                          binary equals 
                                            member 
                                              member 
                                                get lexical 
                                                  identifier token
                                              get dot 
                                                identifier type
                                            member 
                                              member 
                                                get lexical 
                                                  identifier JSONTokenType
                                              get dot 
                                                identifier RIGHT_BRACE 
                                        statementlist 
                                          return 
                                            list 
                                              member 
                                                get lexical 
                                                  identifier o   
                                statementlist 
                                  expression 
                                    list 
                                      member 
                                        member 
                                          get lexical 
                                            identifier tokenizer
                                        call dot 
                                          identifier parseError
                                          argumentlist 
                                            binary plus 
                                              literalstring:Expecting } or , but found 
                                              member 
                                                member 
                                                  get lexical 
                                                    identifier token
                                                get dot 
                                                  identifier value 
                        statementlist 
                          expression 
                            list 
                              member 
                                member 
                                  get lexical 
                                    identifier tokenizer
                                call dot 
                                  identifier parseError
                                  argumentlist 
                                    binary plus 
                                      literalstring:Expecting : but found 
                                      member 
                                        member 
                                          get lexical 
                                            identifier token
                                        get dot 
                                          identifier value 
                    statementlist 
                      expression 
                        list 
                          member 
                            member 
                              get lexical 
                                identifier tokenizer
                            call dot 
                              identifier parseError
                              argumentlist 
                                binary plus 
                                  literalstring:Expecting string but found 
                                  member 
                                    member 
                                      get lexical 
                                        identifier token
                                    get dot 
                                      identifier value
              return 
                list 
                  literalnull
              return 
        function 
          attributelist 
            member 
              get lexical 
                identifier final
            list 
              member 
                get lexical 
                  identifier private
          functionname 
            qualifiedidentifier parseValue 
              qualifier 
                attributelist 
                  member 
                    get lexical 
                      identifier final
                  list 
                    member 
                      get lexical 
                        identifier private
          functioncommon 
            functionsignature 
              typeexpr 
                member 
                  get lexical 
                    identifier Object
            statementlist 
              expression 
                list 
                  member 
                    call lexical 
                      identifier checkValidToken
              switch 
                list 
                  member 
                    member 
                      get lexical 
                        identifier token
                    get dot 
                      identifier type 
                statementlist 
                  case 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier JSONTokenType
                        get dot 
                          identifier LEFT_BRACE
                  return 
                    list 
                      member 
                        call lexical 
                          identifier parseObject
                  case 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier JSONTokenType
                        get dot 
                          identifier LEFT_BRACKET
                  return 
                    list 
                      member 
                        call lexical 
                          identifier parseArray
                  case 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier JSONTokenType
                        get dot 
                          identifier STRING
                  case 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier JSONTokenType
                        get dot 
                          identifier NUMBER
                  case 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier JSONTokenType
                        get dot 
                          identifier TRUE
                  case 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier JSONTokenType
                        get dot 
                          identifier FALSE
                  case 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier JSONTokenType
                        get dot 
                          identifier NULL
                  return 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier token
                        get dot 
                          identifier value
                  case 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier JSONTokenType
                        get dot 
                          identifier NAN
                  if 
                    list 
                      unary not 
                        member 
                          get lexical 
                            identifier strict 
                    statementlist 
                      return 
                        list 
                          member 
                            member 
                              get lexical 
                                identifier token
                            get dot 
                              identifier value 
                    statementlist 
                      expression 
                        list 
                          member 
                            member 
                              get lexical 
                                identifier tokenizer
                            call dot 
                              identifier parseError
                              argumentlist 
                                binary plus 
                                  literalstring:Unexpected 
                                  member 
                                    member 
                                      get lexical 
                                        identifier token
                                    get dot 
                                      identifier value
                  case default
                  expression 
                    list 
                      member 
                        member 
                          get lexical 
                            identifier tokenizer
                        call dot 
                          identifier parseError
                          argumentlist 
                            binary plus 
                              literalstring:Unexpected 
                              member 
                                member 
                                  get lexical 
                                    identifier token
                                get dot 
                                  identifier value
              return 
                list 
                  literalnull
              return 
    package 
      packagename 
        packageidentifiers 
          identifier com
          identifier adobe
          identifier serialization
          identifier json
